// 07-file-io/file-management/main.c

#include <stdio.h>
#include <stdlib.h>

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
    
    // 2. Créer et supprimer un répertoire (non standard C, dépend du système)
    // Pour Linux/macOS, vous pouvez utiliser system("mkdir mon_repertoire");
    // Pour Windows, system("mkdir mon_repertoire");
    printf("\n2. Création et suppression de répertoire (exemple conceptuel):\n");
    printf("   (Fonctions spécifiques au système d'exploitation nécessaires)");

    return 0;
}
