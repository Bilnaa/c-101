// 03-functions/basic-functions/main.c

#include <stdio.h>

// Déclaration de fonction
int addition(int a, int b) {
    return a + b;
}

void saluer(char *nom) {
    printf("Bonjour, %s!\n", nom);
}

int main() {
    printf("=== FONCTIONS DE BASE EN C ===\n\n");
    
    // Appel de fonction avec retour de valeur
    int resultat = addition(5, 3);
    printf("L'addition de 5 et 3 est : %d\n", resultat);
    
    // Appel de fonction sans retour de valeur
    saluer("Alice");
    
    return 0;
}
