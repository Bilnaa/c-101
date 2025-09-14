#include <stdio.h>
#include <stdlib.h>

int *creerPointeurDangling() {
    int local_variable = 100;
    // Retourne l'adresse d'une variable locale, qui sera désallouée après la sortie de la fonction.
    // Cela crée un pointeur "dangling".
    return &local_variable; 
}

int main() {
    printf("=== DÉMONSTRATION D'UN POINTEUR PENDANT (DANGLING POINTER) ===\n\n");
    
    int *dangling_ptr = creerPointeurDangling();
    
    // À ce stade, local_variable n'existe plus, donc 'dangling_ptr' pointe vers une mémoire invalide.
    // Déréférencer ce pointeur est un comportement indéfini et peut causer un crash ou des données corrompues.
    printf("Tentative d'accès à la valeur via le pointeur pendant...\n");
    // L'accès à *dangling_ptr peut fonctionner par 'chance' ou provoquer une erreur de segmentation.
    // Le comportement est indéfini et ne doit jamais être fait en production.
    printf("Valeur (potentiellement) lue: %d\n", *dangling_ptr); 
    
    // Pour accentuer le problème, une autre allocation pourrait réutiliser cette zone mémoire.
    int *another_var = (int *)malloc(sizeof(int));
    if (another_var != NULL) {
        *another_var = 200;
        printf("Une autre variable allouée dynamiquement: %d\n", *another_var);
        printf("Valeur (potentiellement) lue par le pointeur pendant après une nouvelle allocation: %d\n", *dangling_ptr);
        free(another_var);
    }
    
    printf("\n=== FIN DE LA DÉMONSTRATION ===\n");
    
    return 0;
}
