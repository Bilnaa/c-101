// 09-projects/calculator/main.c

#include <stdio.h>

int main() {
    printf("=== PROJET: CALCULATRICE SIMPLE ===\n\n");
    char operateur;
    double nombre1, nombre2, resultat;

    printf("Entrez un opérateur (+, -, *, /): ");
    scanf("%c", &operateur);

    printf("Entrez deux nombres: ");
    scanf("%lf %lf", &nombre1, &nombre2);

    switch (operateur) {
        case '+':
            resultat = nombre1 + nombre2;
            printf("%.1lf + %.1lf = %.1lf\n", nombre1, nombre2, resultat);
            break;
        case '-':
            resultat = nombre1 - nombre2;
            printf("%.1lf - %.1lf = %.1lf\n", nombre1, nombre2, resultat);
            break;
        case '*':
            resultat = nombre1 * nombre2;
            printf("%.1lf * %.1lf = %.1lf\n", nombre1, nombre2, resultat);
            break;
        case '/':
            if (nombre2 != 0) {
                resultat = nombre1 / nombre2;
                printf("%.1lf / %.1lf = %.1lf\n", nombre1, nombre2, resultat);
            } else {
                printf("Erreur: Division par zéro!\n");
            }
            break;
        default:
            printf("Erreur: Opérateur invalide!\n");
    }

    return 0;
}
