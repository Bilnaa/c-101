// 03-functions/recursion/main.c

#include <stdio.h>

// Fonction récursive pour calculer la factorielle d'un nombre
int factorielle(int n) {
    if (n == 0) {
        return 1; // Cas de base
    } else {
        return n * factorielle(n - 1); // Appel récursif
    }
}

// Fonction récursive pour afficher la suite de Fibonacci
int fibonacci(int n) {
    if (n <= 1) {
        return n; // Cas de base
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // Appel récursif
    }
}

int main() {
    printf("=== RÉCURSION EN C ===\n\n");
    
    // Exemple de factorielle
    int nombre_fact = 5;
    printf("La factorielle de %d est : %d\n", nombre_fact, factorielle(nombre_fact));
    
    // Exemple de suite de Fibonacci
    int termes_fib = 6;
    printf("Suite de Fibonacci jusqu'à %d termes : ", termes_fib);
    for (int i = 0; i < termes_fib; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}
