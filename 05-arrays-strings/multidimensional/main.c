// 05-arrays-strings/multidimensional/main.c

#include <stdio.h>

int main() {
    printf("=== TABLEAUX MULTIDIMENSIONNELS EN C ===\n\n");
    
    // Déclaration et initialisation d'un tableau 2D (matrice)
    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    printf("1. Affichage d'une matrice 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("   %d ", matrice[i][j]);
        }
        printf("\n");
    }
    
    // Accès et modification d'un élément
    matrice[1][1] = 50;
    printf("\n2. Élément modifié (matrice[1][1] = %d):\n", matrice[1][1]);
    
    printf("3. Parcours avec boucles imbriquées:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("   matrice[%d][%d] = %d\n", i, j, matrice[i][j]);
        }
    }
    
    // Exemple de tableau 2D de caractères (tableau de chaînes)
    char *noms[] = {"Alice", "Bob", "Charlie"};
    int nb_noms = sizeof(noms) / sizeof(noms[0]);
    
    printf("\n4. Tableau de chaînes de caractères:\n");
    for (int i = 0; i < nb_noms; i++) {
        printf("   Nom %d: %s\n", i + 1, noms[i]);
    }
    
    return 0;
}
