// 06-structures/unions/main.c

#include <stdio.h>
#include <string.h>

// Définition d'une union 'Donnee'
union Donnee {
    int entier;
    float flottant;
    char chaine[20];
};

int main() {
    printf("=== UNIONS EN C ===\n\n");
    
    union Donnee d;
    
    // 1. Stocker un entier
    d.entier = 10;
    printf("1. Après avoir stocké un entier:\n");
    printf("   Entier: %d\n", d.entier);
    // Les autres membres contiennent des données 'garbage'
    // printf("   Flottant: %f\n", d.flottant);
    // printf("   Chaîne: %s\n", d.chaine);
    
    // 2. Stocker un flottant
    d.flottant = 22.5;
    printf("\n2. Après avoir stocké un flottant:\n");
    printf("   Flottant: %f\n", d.flottant);
    printf("   Entier (garbage): %d\n", d.entier); // Contient des données incorrectes
    
    // 3. Stocker une chaîne de caractères
    strcpy(d.chaine, "Hello Union");
    printf("\n3. Après avoir stocké une chaîne:\n");
    printf("   Chaîne: %s\n", d.chaine);
    printf("   Entier (garbage): %d\n", d.entier); // Contient des données incorrectes
    printf("   Flottant (garbage): %f\n", d.flottant); // Contient des données incorrectes
    
    printf("\n4. Taille de l'union: %zu octets (taille du plus grand membre)\n", sizeof(union Donnee));
    
    return 0;
}
