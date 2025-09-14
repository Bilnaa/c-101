// 04-pointers/dynamic-memory/main.c

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== ALLOCATION DYNAMIQUE DE MÉMOIRE EN C ===\n\n");
    
    int *tableau_dyn = NULL;
    int taille;
    
    printf("1. Allocation avec malloc():\n");
    printf("   Entrez la taille du tableau à allouer: ");
    scanf("%d", &taille);
    
    tableau_dyn = (int *) malloc(taille * sizeof(int));
    
    if (tableau_dyn == NULL) {
        printf("   L'allocation mémoire a échoué!\n");
        return 1;
    }
    
    printf("   Mémoire allouée avec malloc. Initialisation:\n");
    for (int i = 0; i < taille; i++) {
        tableau_dyn[i] = (i + 1) * 10;
        printf("   %d ", tableau_dyn[i]);
    }
    printf("\n");
    
    // 2. Réallocation avec realloc()
    printf("\n2. Réallocation avec realloc():\n");
    int nouvelle_taille = taille * 2;
    tableau_dyn = (int *) realloc(tableau_dyn, nouvelle_taille * sizeof(int));
    
    if (tableau_dyn == NULL) {
        printf("   La réallocation mémoire a échoué!\n");
        return 1;
    }
    
    printf("   Mémoire réallouée. Nouvelle taille: %d. Initialisation des nouveaux éléments:\n", nouvelle_taille);
    for (int i = taille; i < nouvelle_taille; i++) {
        tableau_dyn[i] = (i + 1) * 10;
    }
    for (int i = 0; i < nouvelle_taille; i++) {
        printf("   %d ", tableau_dyn[i]);
    }
    printf("\n");
    
    // 3. Libération de mémoire avec free()
    printf("\n3. Libération de mémoire avec free():\n");
    free(tableau_dyn);
    tableau_dyn = NULL; // Bonne pratique: éviter les pointeurs pendants
    printf("   Mémoire libérée avec free.\n");
    
    // 4. Allocation avec calloc()
    printf("\n4. Allocation avec calloc():\n");
    int *tableau_calloc = (int *) calloc(5, sizeof(int)); // Alloue 5 entiers et initialise à zéro
    if (tableau_calloc == NULL) {
        printf("   L'allocation mémoire avec calloc a échoué!\n");
        return 1;
    }
    printf("   Tableau alloué avec calloc (initialisé à zéro):\n");
    for (int i = 0; i < 5; i++) {
        printf("   %d ", tableau_calloc[i]);
    }
    printf("\n");
    free(tableau_calloc);
    tableau_calloc = NULL;
    
    return 0;
}
