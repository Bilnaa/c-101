#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour démontrer les pointeurs sur structures
typedef struct {
    int id;
    char nom[50];
    float note;
} Etudiant;

// Fonction qui utilise des pointeurs comme paramètres
void modifierValeur(int *ptr) {
    *ptr = 100; // Modification de la valeur pointée
}

// Fonction qui retourne un pointeur
int* creerTableau(int taille) {
    int *tab = (int*)malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++) {
        tab[i] = i * 10;
    }
    return tab;
}

// Fonction qui utilise des pointeurs sur structures
void afficherEtudiant(Etudiant *etudiant) {
    printf("ID: %d, Nom: %s, Note: %.2f\n", 
           etudiant->id, etudiant->nom, etudiant->note);
}

int main() {
    printf("=== SHOWCASE DES POINTEURS EN C ===\n\n");
    
    // 1. Pointeurs de base
    printf("1. POINTEURS DE BASE:\n");
    int nombre = 42;
    int *ptr_nombre = &nombre; // Adresse de 'nombre'
    
    printf("Valeur de 'nombre': %d\n", nombre);
    printf("Adresse de 'nombre': %p\n", &nombre);
    printf("Valeur de 'ptr_nombre': %p\n", ptr_nombre);
    printf("Valeur pointée par 'ptr_nombre': %d\n", *ptr_nombre);
    printf("\n");
    
    // 2. Modification via pointeur
    printf("2. MODIFICATION VIA POINTEUR:\n");
    printf("Avant modification: %d\n", nombre);
    *ptr_nombre = 99; // Modification directe
    printf("Après modification directe: %d\n", nombre);
    
    modifierValeur(&nombre); // Modification via fonction
    printf("Après modification via fonction: %d\n", nombre);
    printf("\n");
    
    // 3. Pointeurs et tableaux
    printf("3. POINTEURS ET TABLEAUX:\n");
    int tableau[5] = {10, 20, 30, 40, 50};
    int *ptr_tableau = tableau; // Équivalent à &tableau[0]
    
    printf("Accès via tableau[2]: %d\n", tableau[2]);
    printf("Accès via *(ptr_tableau + 2): %d\n", *(ptr_tableau + 2));
    printf("Accès via ptr_tableau[2]: %d\n", ptr_tableau[2]);
    
    // Parcours du tableau avec pointeur
    printf("Parcours avec pointeur: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr_tableau + i));
    }
    printf("\n\n");
    
    // 4. Allocation dynamique de mémoire
    printf("4. ALLOCATION DYNAMIQUE:\n");
    int taille = 3;
    int *tab_dynamique = creerTableau(taille);
    
    printf("Tableau alloué dynamiquement: ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab_dynamique[i]);
    }
    printf("\n");
    
    // Libération de la mémoire
    free(tab_dynamique);
    printf("Mémoire libérée\n\n");
    
    // 5. Pointeurs sur chaînes de caractères
    printf("5. POINTEURS SUR CHAÎNES:\n");
    char *message = "Bonjour le monde!";
    printf("Message: %s\n", message);
    printf("Premier caractère: %c\n", *message);
    printf("Troisième caractère: %c\n", *(message + 2));
    
    // Modification d'un tableau de caractères
    char texte[] = "Hello";
    char *ptr_texte = texte;
    ptr_texte[0] = 'h'; // Modification possible car c'est un tableau
    printf("Texte modifié: %s\n\n", texte);
    
    // 6. Pointeurs sur structures
    printf("6. POINTEURS SUR STRUCTURES:\n");
    Etudiant etudiant1 = {1, "Alice", 85.5};
    Etudiant *ptr_etudiant = &etudiant1;
    
    printf("Accès via structure: ");
    printf("ID: %d, Nom: %s, Note: %.2f\n", 
           etudiant1.id, etudiant1.nom, etudiant1.note);
    
    printf("Accès via pointeur: ");
    printf("ID: %d, Nom: %s, Note: %.2f\n", 
           ptr_etudiant->id, ptr_etudiant->nom, ptr_etudiant->note);
    
    // Modification via pointeur
    ptr_etudiant->note = 92.0;
    printf("Note modifiée via pointeur: %.2f\n\n", etudiant1.note);
    
    // 7. Tableau de pointeurs
    printf("7. TABLEAU DE POINTEURS:\n");
    char *couleurs[] = {"Rouge", "Vert", "Bleu", "Jaune"};
    int nb_couleurs = 4;
    
    printf("Couleurs disponibles:\n");
    for (int i = 0; i < nb_couleurs; i++) {
        printf("  %d. %s\n", i + 1, couleurs[i]);
    }
    printf("\n");
    
    // 8. Pointeurs de pointeurs
    printf("8. POINTEURS DE POINTEURS:\n");
    int valeur = 42;
    int *ptr1 = &valeur;
    int **ptr2 = &ptr1;
    
    printf("Valeur: %d\n", valeur);
    printf("Valeur via ptr1: %d\n", *ptr1);
    printf("Valeur via ptr2: %d\n", **ptr2);
    printf("Adresse de ptr1: %p\n", &ptr1);
    printf("Adresse stockée dans ptr2: %p\n", *ptr2);
    printf("\n");
    
    // 9. Pointeurs et fonctions
    printf("9. POINTEURS ET FONCTIONS:\n");
    void afficherEtudiant(Etudiant *etudiant);
    afficherEtudiant(&etudiant1);
    
    // 10. Arithmétique des pointeurs
    printf("10. ARITHMÉTIQUE DES POINTEURS:\n");
    int *ptr_arithmetique = tableau;
    printf("Position initiale: %p (valeur: %d)\n", ptr_arithmetique, *ptr_arithmetique);
    
    ptr_arithmetique++; // Incrémentation
    printf("Après ++: %p (valeur: %d)\n", ptr_arithmetique, *ptr_arithmetique);
    
    ptr_arithmetique += 2; // Addition
    printf("Après += 2: %p (valeur: %d)\n", ptr_arithmetique, *ptr_arithmetique);
    
    printf("\n=== FIN DU SHOWCASE ===\n");
    
    return 0;
}
