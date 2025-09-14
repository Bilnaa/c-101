// 08-advanced/error-handling/main.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Fonction qui simule une division par zéro
double diviser(int a, int b) {
    if (b == 0) {
        errno = EDOM; // Domaine d'erreur pour division par zéro
        return 0.0;
    }
    return (double)a / b;
}

int main() {
    printf("=== GESTION DES ERREURS EN C ===\n\n");
    
    // 1. Gestion des erreurs avec errno
    printf("1. GESTION DES ERREURS AVEC errno:\n");
    FILE *fichier = fopen("non_existant.txt", "r");
    if (fichier == NULL) {
        printf("   Erreur d'ouverture de fichier: %s\n", strerror(errno));
    } else {
        printf("   Fichier ouvert avec succès (ce ne devrait pas arriver).\n");
        fclose(fichier);
    }
    
    // Exemple de division par zéro
    printf("\n   Tentative de division par zéro (10 / 0):\n");
    errno = 0; // Réinitialiser errno
    double result = diviser(10, 0);
    if (errno == EDOM) {
        printf("   Erreur: Division par zéro détectée! %s\n", strerror(errno));
    } else {
        printf("   Résultat de la division: %.2f\n", result);
    }

    // 2. Gestion des erreurs avec les codes de retour
    printf("\n2. GESTION DES ERREURS AVEC CODES DE RETOUR:\n");
    // Une fonction qui retourne 0 en cas de succès, -1 en cas d'erreur
    int operation_reussie = 0; // Supposons un succès
    if (operation_reussie != 0) {
        printf("   Erreur lors de l'opération.\n");
    } else {
        printf("   Opération réussie.\n");
    }
    
    // 3. Utilisation de assert (pour le débogage)
    printf("\n3. UTILISATION DE assert (POUR LE DÉBOGAGE):\n");
    int x = 10;
    // #include <assert.h>
    // assert(x == 10); // Ne fera rien si x est 10
    // assert(x == 5); // Arrêtera le programme si NDEBUG n'est pas défini
    printf("   assert est utile pour détecter des conditions inattendues pendant le développement.\n");
    printf("   Pour l'exemple, assert(x == 5) n'est pas exécuté pour ne pas arrêter le programme.\n");

    return 0;
}
