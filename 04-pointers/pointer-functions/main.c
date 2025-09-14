// 04-pointers/pointer-functions/main.c

#include <stdio.h>
#include <stdlib.h> // Pour malloc et free

// Fonction qui modifie une variable via un pointeur (passage par référence)
void doublerValeur(int *valeur_ptr) {
    *valeur_ptr = *valeur_ptr * 2;
}

// Fonction qui retourne un pointeur vers un tableau alloué dynamiquement
int* creerTableauDynamique(int taille) {
    int *tableau = (int *) malloc(taille * sizeof(int));
    if (tableau == NULL) {
        return NULL; // Gestion d'erreur
    }
    for (int i = 0; i < taille; i++) {
        tableau[i] = (i + 1) * 100;
    }
    return tableau;
}

// Fonction de comparaison pour qsort (pointeurs de fonctions)
int comparerEntiers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    printf("=== POINTEURS ET FONCTIONS EN C ===\n\n");
    
    // 1. Passage de paramètres par référence
    printf("1. Passage de paramètres par référence:\n");
    int nombre = 10;
    printf("   Avant: nombre = %d\n", nombre);
    doublerValeur(&nombre);
    printf("   Après doublerValeur(): nombre = %d\n", nombre);
    
    // 2. Retour de pointeurs depuis une fonction
    printf("\n2. Retour de pointeurs:\n");
    int taille_tab = 5;
    int *mon_tableau = creerTableauDynamique(taille_tab);
    
    if (mon_tableau != NULL) {
        printf("   Tableau créé dynamiquement: ");
        for (int i = 0; i < taille_tab; i++) {
            printf("%d ", mon_tableau[i]);
        }
        printf("\n");
        free(mon_tableau); // Libérer la mémoire allouée
    } else {
        printf("   Erreur: Allocation de tableau échouée.\n");
    }
    
    // 3. Pointeurs de fonctions (Callbacks)
    printf("\n3. Pointeurs de fonctions (Callbacks):\n");
    int chiffres[] = {5, 2, 8, 1, 9};
    int nb_chiffres = sizeof(chiffres) / sizeof(chiffres[0]);
    
    printf("   Tableau avant tri: ");
    for (int i = 0; i < nb_chiffres; i++) {
        printf("%d ", chiffres[i]);
    }
    printf("\n");
    
    // Utilisation de qsort avec un pointeur de fonction
    qsort(chiffres, nb_chiffres, sizeof(int), comparerEntiers);
    
    printf("   Tableau après tri (qsort): ");
    for (int i = 0; i < nb_chiffres; i++) {
        printf("%d ", chiffres[i]);
    }
    printf("\n");
    
    return 0;
}
