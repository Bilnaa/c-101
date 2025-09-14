// Boucles en C
#include <stdio.h>

int main() {
    printf("=== STRUCTURES DE CONTRÔLE - BOUCLES ===\n\n");
    
    // 1. Boucle for
    printf("1. BOUCLE FOR:\n");
    printf("   Comptage de 1 à 5: ");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Boucle for avec pas différent
    printf("   Comptage de 0 à 10 par pas de 2: ");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Boucle for décroissante
    printf("   Comptage décroissant de 5 à 1: ");
    for (int i = 5; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 2. Boucle while
    printf("2. BOUCLE WHILE:\n");
    int compteur = 1;
    printf("   Comptage avec while: ");
    while (compteur <= 3) {
        printf("%d ", compteur);
        compteur++;
    }
    printf("\n");
    
    // Boucle while avec condition complexe
    int nombre = 1;
    printf("   Puissances de 2 jusqu'à 16: ");
    while (nombre <= 16) {
        printf("%d ", nombre);
        nombre *= 2;
    }
    printf("\n\n");
    
    // 3. Boucle do-while
    printf("3. BOUCLE DO-WHILE:\n");
    int valeur = 0;
    printf("   Comptage avec do-while: ");
    do {
        printf("%d ", valeur);
        valeur++;
    } while (valeur < 3);
    printf("\n");
    
    // do-while s'exécute au moins une fois
    int choix = 0;
    printf("   Simulation d'un menu (do-while): ");
    do {
        printf("Menu ");
        choix++;
    } while (choix < 1); // S'exécute une seule fois
    printf("\n\n");
    
    // 4. Boucles imbriquées
    printf("4. BOUCLES IMBRIQUÉES:\n");
    printf("   Table de multiplication (3x3):\n");
    for (int i = 1; i <= 3; i++) {
        printf("   ");
        for (int j = 1; j <= 3; j++) {
            printf("%2d ", i * j);
        }
        printf("\n");
    }
    printf("\n");
    
    // 5. Instructions de contrôle dans les boucles
    printf("5. INSTRUCTIONS DE CONTRÔLE:\n");
    
    // break
    printf("   Boucle avec break (s'arrête à 3): ");
    for (int i = 1; i <= 5; i++) {
        if (i == 4) break;
        printf("%d ", i);
    }
    printf("\n");
    
    // continue
    printf("   Boucle avec continue (ignore les nombres pairs): ");
    for (int i = 1; i <= 6; i++) {
        if (i % 2 == 0) continue;
        printf("%d ", i);
    }
    printf("\n\n");
    
    // 6. Boucles avec tableaux
    printf("6. BOUCLES AVEC TABLEAUX:\n");
    int nombres[] = {10, 20, 30, 40, 50};
    int taille = sizeof(nombres) / sizeof(nombres[0]);
    
    printf("   Éléments du tableau: ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", nombres[i]);
    }
    printf("\n");
    
    // Somme des éléments
    int somme = 0;
    for (int i = 0; i < taille; i++) {
        somme += nombres[i];
    }
    printf("   Somme des éléments: %d\n", somme);
    
    return 0;
}
