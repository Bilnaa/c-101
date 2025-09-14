//Types de Données en C

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    printf("=== TYPES DE DONNÉES EN C ===\n\n");
    
    // Types entiers
    printf("1. TYPES ENTIERS:\n");
    printf("   char: %d à %d (taille: %zu octets)\n", CHAR_MIN, CHAR_MAX, sizeof(char));
    printf("   short: %d à %d (taille: %zu octets)\n", SHRT_MIN, SHRT_MAX, sizeof(short));
    printf("   int: %d à %d (taille: %zu octets)\n", INT_MIN, INT_MAX, sizeof(int));
    printf("   long: %ld à %ld (taille: %zu octets)\n", LONG_MIN, LONG_MAX, sizeof(long));
    printf("   long long: %lld à %lld (taille: %zu octets)\n", LLONG_MIN, LLONG_MAX, sizeof(long long));
    
    // Types non signés
    printf("\n2. TYPES NON SIGNÉS:\n");
    printf("   unsigned char: 0 à %u (taille: %zu octets)\n", UCHAR_MAX, sizeof(unsigned char));
    printf("   unsigned int: 0 à %u (taille: %zu octets)\n", UINT_MAX, sizeof(unsigned int));
    printf("   unsigned long: 0 à %lu (taille: %zu octets)\n", ULONG_MAX, sizeof(unsigned long));
    
    // Types flottants
    printf("\n3. TYPES FLOTTANTS:\n");
    printf("   float: %e à %e (taille: %zu octets)\n", FLT_MIN, FLT_MAX, sizeof(float));
    printf("   double: %e à %e (taille: %zu octets)\n", DBL_MIN, DBL_MAX, sizeof(double));
    printf("   long double: %Le à %Le (taille: %zu octets)\n", LDBL_MIN, LDBL_MAX, sizeof(long double));
    
    // Exemples d'utilisation
    printf("\n4. EXEMPLES D'UTILISATION:\n");
    
    char caractere = 'A';
    int nombre_entier = 42;
    float nombre_decimal = 3.14159f;
    double precision_double = 2.718281828459045;
    
    printf("   Caractère: %c (code ASCII: %d)\n", caractere, caractere);
    printf("   Entier: %d\n", nombre_entier);
    printf("   Float: %.5f\n", nombre_decimal);
    printf("   Double: %.15f\n", precision_double);
    
    // Modificateurs
    printf("\n5. MODIFICATEURS:\n");
    const int CONSTANTE = 100;
    volatile int variable_volatile = 200;
    
    printf("   Constante: %d\n", CONSTANTE);
    printf("   Variable volatile: %d\n", variable_volatile);
    
    return 0;
}
