// 04-pointers/pointer-arithmetic/main.c

#include <stdio.h>

int main() {
    printf("=== ARITHMÉTIQUE DES POINTEURS EN C ===\n\n");
    
    int nombres[] = {10, 20, 30, 40, 50};
    int *ptr = nombres; // Pointeur vers le début du tableau
    
    printf("Adresse de nombres[0]: %p, Valeur: %d\n", (void*)&nombres[0], nombres[0]);
    printf("Pointeur initial (ptr): %p, Valeur pointée: %d\n", (void*)ptr, *ptr);
    
    // 1. Incrémentation d'un pointeur (ptr++)
    ptr++; // ptr pointe maintenant vers nombres[1]
    printf("\n1. Après ptr++ : %p, Valeur pointée: %d\n", (void*)ptr, *ptr);
    
    // 2. Décrémentation d'un pointeur (ptr--)
    ptr--; // ptr pointe à nouveau vers nombres[0]
    printf("\n2. Après ptr-- : %p, Valeur pointée: %d\n", (void*)ptr, *ptr);
    
    // 3. Addition à un pointeur (ptr + n)
    ptr = ptr + 3; // ptr pointe vers nombres[3]
    printf("\n3. Après ptr + 3 : %p, Valeur pointée: %d\n", (void*)ptr, *ptr);
    
    // 4. Soustraction à un pointeur (ptr - n)
    ptr = ptr - 2; // ptr pointe vers nombres[1]
    printf("\n4. Après ptr - 2 : %p, Valeur pointée: %d\n", (void*)ptr, *ptr);
    
    // 5. Différence entre deux pointeurs (ptr2 - ptr1)
    int *ptr1 = &nombres[1];
    int *ptr2 = &nombres[4];
    
    long difference = ptr2 - ptr1; // Nombre d'éléments entre ptr1 et ptr2
    printf("\n5. Différence entre ptr2 et ptr1: %ld éléments\n", difference);
    printf("   (ptr2 pointe vers %d, ptr1 pointe vers %d)\n", *ptr2, *ptr1);
    
    // 6. Comparaison de pointeurs
    printf("\n6. Comparaison de pointeurs:\n");
    if (ptr1 < ptr2) {
        printf("   ptr1 est avant ptr2 dans la mémoire.\n");
    }
    if (ptr1 == &nombres[1]) {
        printf("   ptr1 pointe vers le deuxième élément du tableau.\n");
    }
    
    return 0;
}
