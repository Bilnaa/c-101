// 07-file-io/file-management/main.c

#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <direct.h>
#define CREATE_DIRECTORY(name) _mkdir(name)
#define REMOVE_DIRECTORY(name) _rmdir(name)
#else
#include <sys/stat.h>
#include <unistd.h> // Pour rmdir sur les systèmes Unix-like
#define CREATE_DIRECTORY(name) mkdir(name, 0777)
#define REMOVE_DIRECTORY(name) rmdir(name)
#endif

int main() {
    printf("=== GESTION DES FICHIERS ET RÉPERTOIRES EN C ===\n\n");
    
    // 1. Renommer un fichier
    FILE *fp = fopen("oldname.txt", "w");
    if (fp == NULL) {
        perror("Erreur lors de la création de oldname.txt");
        return 1;
    }
    fprintf(fp, "Ceci est un fichier temporaire.\n");
    fclose(fp);
    printf("1. Fichier 'oldname.txt' créé.\n");
    
    if (rename("oldname.txt", "newname.txt") == 0) {
        printf("   Fichier renommé de 'oldname.txt' à 'newname.txt'.\n");
    } else {
        perror("Erreur lors du renommage du fichier");
    }
    
    // Nettoyage après renommage
    if (remove("newname.txt") == 0) {
        printf("   Fichier 'newname.txt' supprimé.\n");
    } else {
        perror("Erreur lors de la suppression de newname.txt");
    }
    
    // 2. Créer et supprimer un répertoire en utilisant des macros
    printf("\n2. Création et suppression de répertoire:\n");
    
    const char* dir_name = "mon_nouveau_repertoire";
    
    if (CREATE_DIRECTORY(dir_name) == 0) {
        printf("   Répertoire '%s' créé avec succès.\n", dir_name);
    } else {
        perror("Erreur lors de la création du répertoire");
    }
    
    if (REMOVE_DIRECTORY(dir_name) == 0) {
        printf("   Répertoire '%s' supprimé avec succès.\n", dir_name);
    } else {
        perror("Erreur lors de la suppression du répertoire");
    }

    return 0;
}
