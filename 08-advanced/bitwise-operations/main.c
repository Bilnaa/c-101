// 08-advanced/bitwise-operations/main.c

#include <stdio.h>

int main() {
    printf("=== OPÉRATIONS BINAIRES EN C ===\n\n");
    
    unsigned int a = 60;  // 0011 1100 en binaire
    unsigned int b = 13;  // 0000 1101 en binaire
    int resultat = 0;
    
    printf("Valeur de a = %u (0b00111100)\n", a);
    printf("Valeur de b = %u (0b00001101)\n", b);
    
    // 1. ET binaire (&)
    resultat = a & b; // 0000 1100 (12)
    printf("\n1. a & b = %d (0b%08x)\n", resultat, resultat);
    
    // 2. OU binaire (|)
    resultat = a | b; // 0011 1101 (61)
    printf("\n2. a | b = %d (0b%08x)\n", resultat, resultat);
    
    // 3. OU Exclusif binaire (^)
    resultat = a ^ b; // 0011 0001 (49)
    printf("\n3. a ^ b = %d (0b%08x)\n", resultat, resultat);
    
    // 4. NON binaire (~)
    resultat = ~a; // 1100 0011 (représentation en complément à deux, -61 si signé)
    printf("\n4. ~a = %d (0x%08x si unsigned int)\n", resultat, resultat);
    
    // 5. Décalage à gauche (<<)
    resultat = a << 2; // 1111 0000 (240)
    printf("\n5. a << 2 = %d (0b%08x)\n", resultat, resultat);
    
    // 6. Décalage à droite (>>)
    resultat = a >> 2; // 0000 1111 (15)
    printf("\n6. a >> 2 = %d (0b%08x)\n", resultat, resultat);
    
    // Exemple: vérifier si un bit est défini
    unsigned int drapeau = 0b00000100; // Bit 2 est défini
    unsigned int valeur_test = 0b00000101; // Bit 0 et 2 sont définis
    
    printf("\n7. Vérification de bit:\n");
    if ( (valeur_test & drapeau) == drapeau) {
        printf("   Le bit correspondant au drapeau est défini dans la valeur de test.\n");
    } else {
        printf("   Le bit n'est pas défini.\n");
    }
    
    // Exemple: définir un bit
    unsigned int registre = 0b00000000;
    unsigned int masque_bit_3 = 0b00001000;
    registre = registre | masque_bit_3;
    printf("   Après avoir défini le bit 3: 0b%08x (%d)\n", registre, registre);

    return 0;
}
