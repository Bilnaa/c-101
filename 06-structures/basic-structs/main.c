// 06-structures/basic-structs/main.c

#include <stdio.h>
#include <string.h>

// Définition d'une structure 'Personne'
struct Personne {
    char nom[50];
    int age;
    float taille;
};

int main() {
    printf("=== STRUCTURES DE BASE EN C ===\n\n");
    
    // Déclaration et initialisation d'une variable de type struct Personne
    struct Personne personne1;
    strcpy(personne1.nom, "Alice");
    personne1.age = 30;
    personne1.taille = 1.65;
    
    printf("1. Informations de la personne 1:\n");
    printf("   Nom: %s\n", personne1.nom);
    printf("   Age: %d\n", personne1.age);
    printf("   Taille: %.2f m\n", personne1.taille);
    
    // Autre méthode d'initialisation
    struct Personne personne2 = {"Bob", 25, 1.80};
    
    printf("\n2. Informations de la personne 2:\n");
    printf("   Nom: %s\n", personne2.nom);
    printf("   Age: %d\n", personne2.age);
    printf("   Taille: %.2f m\n", personne2.taille);
    
    // Tableaux de structures
    struct Personne etudiants[2];
    strcpy(etudiants[0].nom, "Charlie");
    etudiants[0].age = 22;
    etudiants[0].taille = 1.70;
    
    strcpy(etudiants[1].nom, "Diana");
    etudiants[1].age = 23;
    etudiants[1].taille = 1.72;
    
    printf("\n3. Informations des étudiants:\n");
    for (int i = 0; i < 2; i++) {
        printf("   Etudiant %d - Nom: %s, Age: %d, Taille: %.2f m\n", 
               i + 1, etudiants[i].nom, etudiants[i].age, etudiants[i].taille);
    }
    
    return 0;
}
