//Variables en C

#include <stdio.h>

int main() {
    // Déclaration et initialisation de variables
    int age = 25;
    char initiale = 'J';
    float taille = 1.75;
    double salaire = 35000.50;
    
    // Affichage des variables
    printf("=== DÉMONSTRATION DES VARIABLES ===\n\n");
    
    printf("Âge: %d ans\n", age);
    printf("Initiale: %c\n", initiale);
    printf("Taille: %.2f m\n", taille);
    printf("Salaire: %.2f euros\n", salaire);
    
    // Modification des valeurs
    printf("\n=== MODIFICATION DES VALEURS ===\n");
    
    age = 26;
    taille = 1.76;
    
    printf("Nouvel âge: %d ans\n", age);
    printf("Nouvelle taille: %.2f m\n", taille);
    
    // Constantes
    const int ANNEE_NAISSANCE = 1998;
    printf("\nAnnée de naissance (constante): %d\n", ANNEE_NAISSANCE);
    
    // Différents types entiers
    printf("\n=== TYPES ENTIERS ===\n");
    short petit_nombre = 32000;
    long grand_nombre = 2000000000L;
    unsigned int nombre_positif = 100;
    
    printf("Short: %hd\n", petit_nombre);
    printf("Long: %ld\n", grand_nombre);
    printf("Unsigned int: %u\n", nombre_positif);
    
    return 0;
}
