// 03-functions/function-pointers/main.c

#include <stdio.h>

// Fonction qui ajoute deux entiers
int add(int a, int b) {
    return a + b;
}

// Fonction qui soustrait deux entiers
int subtract(int a, int b) {
    return a - b;
}

// Fonction qui multiplie deux entiers
int multiply(int a, int b) {
    return a * b;
}

int main() {
    printf("=== POINTEURS DE FONCTIONS EN C ===\n\n");
    
    // Déclaration d'un pointeur de fonction
    int (*operation)(int, int);
    
    // Assignation de la fonction add au pointeur
    operation = add;
    printf("Addition: 10 + 5 = %d\n", operation(10, 5));
    
    // Assignation de la fonction subtract au pointeur
    operation = subtract;
    printf("Soustraction: 10 - 5 = %d\n", operation(10, 5));
    
    // Assignation de la fonction multiply au pointeur
    operation = multiply;
    printf("Multiplication: 10 * 5 = %d\n", operation(10, 5));
    
    return 0;
}
