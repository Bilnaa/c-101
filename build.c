// Système de build C-101 avec nob.h

#define NOB_IMPLEMENTATION
#include "vendor/nob.h/nob.h"

// Configuration du projet
#define PROJECT_NAME "c-101"
#define BUILD_DIR "build_output"
#define CC "gcc"
#define CFLAGS "-Wall", "-Wextra", "-std=c99", "-g"

// Couleurs pour les messages (ANSI)
#define COLOR_GREEN   "\033[0;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_RED     "\033[0;31m"
#define COLOR_BLUE    "\033[0;34m"
#define COLOR_RESET   "\033[0m"

// Structure pour représenter un exemple
typedef struct {
    const char *name;
    const char *source_path;
    const char *output_name;
    bool enabled;
} Example;

// Liste des exemples disponibles
static Example examples[] = {
    // 01-basics
    {"hello-world", "01-basics/hello-world/main.c", "hello-world", true},
    {"variables", "01-basics/variables/main.c", "variables", true},
    {"data-types", "01-basics/data-types/main.c", "data-types", true},
    
    // 02-control-flow
    {"conditions", "02-control-flow/conditions/main.c", "conditions", true},
    {"loops", "02-control-flow/loops/main.c", "loops", true},
    
    // 04-pointers
    {"pointers-showcase", "04-pointers/basic-pointers/main.c", "pointers-showcase", true},
};

#define EXAMPLES_COUNT (sizeof(examples) / sizeof(examples[0]))

// Fonction pour créer le dossier de build
static bool setup_build_dir(void) {
    if (!nob_mkdir_if_not_exists(BUILD_DIR)) {
        nob_log(NOB_ERROR, "Impossible de créer le dossier %s", BUILD_DIR);
        return false;
    }
    return true;
}

// Fonction pour compiler un exemple
static bool compile_example(const Example *example) {
    nob_log(NOB_INFO, COLOR_YELLOW "Compilation de %s..." COLOR_RESET, example->name);
    
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, CC);
    nob_cmd_append(&cmd, CFLAGS);
    nob_cmd_append(&cmd, "-o");
    
    char output_path[256];
    snprintf(output_path, sizeof(output_path), "%s/%s", BUILD_DIR, example->output_name);
    nob_cmd_append(&cmd, output_path);
    nob_cmd_append(&cmd, example->source_path);
    
    if (!nob_cmd_run_sync(cmd)) {
        nob_log(NOB_ERROR, COLOR_RED "Erreur de compilation pour %s" COLOR_RESET, example->name);
        return false;
    }
    
    nob_log(NOB_INFO, COLOR_GREEN "✓ %s compilé avec succès" COLOR_RESET, example->name);
    return true;
}

// Fonction pour exécuter un exemple
static bool run_example(const Example *example) {
    char output_path[256];
    snprintf(output_path, sizeof(output_path), "%s/%s", BUILD_DIR, example->output_name);
    
    if (!nob_file_exists(output_path)) {
        nob_log(NOB_ERROR, COLOR_RED "Exécutable %s non trouvé. Compilez d'abord avec: ./build %s" COLOR_RESET, 
                example->output_name, example->name);
        return false;
    }
    
    nob_log(NOB_INFO, COLOR_BLUE "Exécution de %s..." COLOR_RESET, example->name);
    
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, output_path);
    
    if (!nob_cmd_run_sync(cmd)) {
        nob_log(NOB_ERROR, COLOR_RED "Erreur d'exécution pour %s" COLOR_RESET, example->name);
        return false;
    }
    
    return true;
}

// Fonction pour nettoyer les fichiers compilés
static bool clean_build(void) {
    nob_log(NOB_INFO, COLOR_YELLOW "Nettoyage des fichiers compilés..." COLOR_RESET);
    
    Nob_Cmd cmd = {0};
    nob_cmd_append(&cmd, "rm");
    nob_cmd_append(&cmd, "-rf");
    nob_cmd_append(&cmd, BUILD_DIR);
    
    if (nob_cmd_run_sync(cmd)) {
        nob_log(NOB_INFO, COLOR_GREEN "✓ Nettoyage terminé" COLOR_RESET);
        return true;
    } else {
        nob_log(NOB_ERROR, COLOR_RED "Erreur lors du nettoyage" COLOR_RESET);
        return false;
    }
}

// Fonction pour afficher l'aide
static void show_help(void) {
    printf(COLOR_GREEN "C-101 Build System avec nob.h" COLOR_RESET "\n\n");
    printf(COLOR_YELLOW "Commandes disponibles:" COLOR_RESET "\n");
    printf("  ./build all              - Compile tous les exemples\n");
    printf("  ./build <nom>            - Compile un exemple spécifique\n");
    printf("  ./build run-<nom>        - Exécute un exemple spécifique\n");
    printf("  ./build clean            - Supprime les fichiers compilés\n");
    printf("  ./build help              - Affiche cette aide\n");
    printf("  ./build list              - Liste tous les exemples disponibles\n");
    printf("\n" COLOR_YELLOW "Exemples disponibles:" COLOR_RESET "\n");
    
    for (size_t i = 0; i < EXAMPLES_COUNT; i++) {
        if (examples[i].enabled) {
            printf("  %s\n", examples[i].name);
        }
    }
    
    printf("\n" COLOR_YELLOW "Exemples d'utilisation:" COLOR_RESET "\n");
    printf("  ./build all\n");
    printf("  ./build hello-world\n");
    printf("  ./build run-hello-world\n");
    printf("  ./build run-pointers-showcase\n");
}

// Fonction pour lister tous les exemples
static void list_examples(void) {
    printf(COLOR_BLUE "Exemples disponibles dans C-101:" COLOR_RESET "\n\n");
    
    for (size_t i = 0; i < EXAMPLES_COUNT; i++) {
        if (examples[i].enabled) {
            printf(COLOR_GREEN "✓ %s" COLOR_RESET " - %s\n", 
                   examples[i].name, examples[i].source_path);
        }
    }
    
    printf("\nTotal: %zu exemples\n", EXAMPLES_COUNT);
}

// Fonction pour trouver un exemple par nom
static Example* find_example(const char *name) {
    for (size_t i = 0; i < EXAMPLES_COUNT; i++) {
        if (strcmp(examples[i].name, name) == 0) {
            return &examples[i];
        }
    }
    return NULL;
}

int main(int argc, char **argv) {
    nob_log(NOB_INFO, COLOR_BLUE "=== C-101 Build System avec nob.h ===" COLOR_RESET);
    
    if (argc < 2) {
        nob_log(NOB_ERROR, "Usage: %s <commande>", argv[0]);
        show_help();
        return 1;
    }
    
    const char *command = argv[1];
    
    // Commande: help
    if (strcmp(command, "help") == 0) {
        show_help();
        return 0;
    }
    
    // Commande: list
    if (strcmp(command, "list") == 0) {
        list_examples();
        return 0;
    }
    
    // Commande: clean
    if (strcmp(command, "clean") == 0) {
        return clean_build() ? 0 : 1;
    }
    
    // Commande: all
    if (strcmp(command, "all") == 0) {
        if (!setup_build_dir()) return 1;
        
        nob_log(NOB_INFO, COLOR_BLUE "Compilation de tous les exemples..." COLOR_RESET);
        
        bool success = true;
        for (size_t i = 0; i < EXAMPLES_COUNT; i++) {
            if (examples[i].enabled) {
                if (!compile_example(&examples[i])) {
                    success = false;
                }
            }
        }
        
        if (success) {
            nob_log(NOB_INFO, COLOR_GREEN "✓ Tous les exemples compilés avec succès !" COLOR_RESET);
        } else {
            nob_log(NOB_ERROR, COLOR_RED "✗ Certains exemples ont échoué" COLOR_RESET);
        }
        
        return success ? 0 : 1;
    }
    
    // Commande: run-<nom>
    if (strncmp(command, "run-", 4) == 0) {
        const char *example_name = command + 4; // Enlever "run-"
        Example *example = find_example(example_name);
        
        if (!example) {
            nob_log(NOB_ERROR, COLOR_RED "Exemple '%s' non trouvé" COLOR_RESET, example_name);
            return 1;
        }
        
        return run_example(example) ? 0 : 1;
    }
    
    // Commande: <nom> (compilation d'un exemple spécifique)
    Example *example = find_example(command);
    if (example) {
        if (!setup_build_dir()) return 1;
        return compile_example(example) ? 0 : 1;
    }
    
    // Commande non reconnue
    nob_log(NOB_ERROR, COLOR_RED "Commande '%s' non reconnue" COLOR_RESET, command);
    show_help();
    return 1;
}
