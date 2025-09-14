// 09-projects/student-management/main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure pour un étudiant
typedef struct {
    int id;
    char nom[50];
    float note;
} Etudiant;

Etudiant etudiants[MAX_STUDENTS];
int nb_etudiants = 0;

// Fonction pour ajouter un étudiant
void ajouter_etudiant() {
    if (nb_etudiants < MAX_STUDENTS) {
        printf("ID de l'étudiant: ");
        scanf("%d", &etudiants[nb_etudiants].id);
        printf("Nom de l'étudiant: ");
        scanf("%s", etudiants[nb_etudiants].nom);
        printf("Note de l'étudiant: ");
        scanf("%f", &etudiants[nb_etudiants].note);
        nb_etudiants++;
        printf("Étudiant ajouté avec succès.\n");
    } else {
        printf("Impossible d'ajouter plus d'étudiants. Limite atteinte.\n");
    }
}

// Fonction pour afficher tous les étudiants
void afficher_etudiants() {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant à afficher.\n");
        return;
    }
    printf("\n--- LISTE DES ÉTUDIANTS ---\n");
    for (int i = 0; i < nb_etudiants; i++) {
        printf("ID: %d, Nom: %s, Note: %.2f\n",
               etudiants[i].id, etudiants[i].nom, etudiants[i].note);
    }
    printf("----------------------------\n");
}

int main() {
    printf("=== PROJET: SYSTÈME DE GESTION DES ÉTUDIANTS ===\n\n");
    int choix;

    do {
        printf("\nMenu:\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher tous les étudiants\n");
        printf("3. Quitter\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter_etudiant();
                break;
            case 2:
                afficher_etudiants();
                break;
            case 3:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);

    return 0;
}
