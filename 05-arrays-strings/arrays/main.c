// 05-arrays-strings/arrays/main.c

#include <stdio.h>

int main() {
    printf("=== TABLEAUX EN C ===\n\n");
    
    // Déclaration et initialisation d'un tableau d'entiers
    int nombres[5] = {10, 20, 30, 40, 50};
    
    printf("1. Accès aux éléments du tableau:\n");
    printf("   Premier élément: %d\n", nombres[0]);
    printf("   Troisième élément: %d\n", nombres[2]);
    
    // Modification d'un élément
    nombres[1] = 25;
    printf("   Deuxième élément modifié: %d\n", nombres[1]);
    
    printf("\n2. Parcours du tableau avec une boucle:\n");
    for (int i = 0; i < 5; i++) {
        printf("   Élément à l'index %d: %d\n", i, nombres[i]);
    }
    
    // Tableau de caractères (chaîne de caractères)
    char voyelles[] = {'a', 'e', 'i', 'o', 'u'};
    int taille_voyelles = sizeof(voyelles) / sizeof(voyelles[0]);
    printf("\n3. Tableau de caractères (voyelles):\n");
    for (int i = 0; i < taille_voyelles; i++) {
        printf("   %c ", voyelles[i]);
    }
    printf("\n");
    
    // Tableau sans taille spécifiée (taille déduite)
    int data[] = {100, 200, 300};
    int taille_data = sizeof(data) / sizeof(data[0]);
    printf("\n4. Tableau avec taille déduite:\n");
    printf("   Taille du tableau data: %d\n", taille_data);
    for (int i = 0; i < taille_data; i++) {
        printf("   %d ", data[i]);
    }
    printf("\n");
    
    return 0;
}
