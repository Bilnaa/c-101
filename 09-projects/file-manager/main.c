// 09-projects/file-manager/main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // Pour la gestion des répertoires

void lister_repertoire(const char *chemin) {
    DIR *d;
    struct dirent *dir;
    d = opendir(chemin);
    if (d) {
        printf("Contenu du répertoire '%s':\n", chemin);
        while ((dir = readdir(d)) != NULL) {
            printf("  %s\n", dir->d_name);
        }
        closedir(d);
    } else {
        perror("Erreur lors de l'ouverture du répertoire");
    }
}

int main() {
    printf("=== PROJET: GESTIONNAIRE DE FICHIERS SIMPLE ===\n\n");
    
    char commande[50];
    char chemin[100];
    
    printf("Commandes disponibles: list <chemin>, exit\n");
    
    while (1) {
        printf("> ");
        scanf("%s", commande);
        
        if (strcmp(commande, "exit") == 0) {
            printf("Exiting file manager.\n");
            break;
        } else if (strcmp(commande, "list") == 0) {
            scanf("%s", chemin);
            lister_repertoire(chemin);
        } else {
            printf("Commande inconnue: %s\n", commande);
        }
    }
    
    return 0;
}
