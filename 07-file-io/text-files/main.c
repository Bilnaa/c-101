// 07-file-io/text-files/main.c

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== GESTION DES FICHIERS TEXTE EN C ===\n\n");
    
    FILE *fichier;
    char ligne[100];
    
    // 1. Écriture dans un fichier (mode "w" - write)
    fichier = fopen("exemple.txt", "w");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en écriture");
        return 1;
    }
    
    fprintf(fichier, "Ceci est la première ligne.\n");
    fputs("Ceci est la deuxième ligne.\n", fichier);
    fclose(fichier);
    printf("1. Fichier 'exemple.txt' créé et écrit.\n");
    
    // 2. Lecture d'un fichier (mode "r" - read)
    fichier = fopen("exemple.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        return 1;
    }
    
    printf("\n2. Contenu de 'exemple.txt':\n");
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("   %s", ligne);
    }
    fclose(fichier);
    
    // 3. Ajout à un fichier (mode "a" - append)
    fichier = fopen("exemple.txt", "a");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en ajout");
        return 1;
    }
    fprintf(fichier, "Nouvelle ligne ajoutée.\n");
    fclose(fichier);
    printf("\n3. Nouvelle ligne ajoutée à 'exemple.txt'.\n");
    
    // Vérifier le contenu après ajout
    fichier = fopen("exemple.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        return 1;
    }
    printf("   Contenu après ajout:\n");
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("   %s", ligne);
    }
    fclose(fichier);
    
    // 4. Suppression du fichier
    if (remove("exemple.txt") == 0) {
        printf("\n4. Fichier 'exemple.txt' supprimé avec succès.\n");
    } else {
        perror("Erreur lors de la suppression du fichier");
    }
    
    return 0;
}
