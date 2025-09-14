// 06-structures/nested-structs/main.c

#include <stdio.h>
#include <string.h>

// Définition d'une structure Adresse
struct Adresse {
    char rue[50];
    char ville[50];
    char code_postal[10];
};

// Définition d'une structure Personne qui contient une structure Adresse (imbriquée)
struct Personne {
    char nom[50];
    int age;
    struct Adresse adresse;
};

int main() {
    printf("=== STRUCTURES IMBRIQUÉES EN C ===\n\n");
    
    // Déclaration et initialisation d'une variable de type struct Personne
    struct Personne personne1;
    strcpy(personne1.nom, "Alice Smith");
    personne1.age = 30;
    strcpy(personne1.adresse.rue, "123 Rue Principale");
    strcpy(personne1.adresse.ville, "Paris");
    strcpy(personne1.adresse.code_postal, "75001");
    
    printf("1. Informations de la personne 1:\n");
    printf("   Nom: %s\n", personne1.nom);
    printf("   Age: %d\n", personne1.age);
    printf("   Adresse: %s, %s %s\n", 
           personne1.adresse.rue, personne1.adresse.ville, personne1.adresse.code_postal);
    
    // Initialisation directe d'une structure imbriquée
    struct Personne personne2 = {
        "Bob Johnson",
        25,
        {"456 Avenue des Champs", "Lyon", "69002"}
    };
    
    printf("\n2. Informations de la personne 2:\n");
    printf("   Nom: %s\n", personne2.nom);
    printf("   Age: %d\n", personne2.age);
    printf("   Adresse: %s, %s %s\n", 
           personne2.adresse.rue, personne2.adresse.ville, personne2.adresse.code_postal);
           
    return 0;
}
