// 07-file-io/binary-files/main.c

#include <stdio.h>
#include <stdlib.h>

// Définition d'une structure pour l'écriture/lecture binaire
typedef struct {
    int id;
    char nom[50];
    float solde;
} CompteBancaire;

int main() {
    printf("=== GESTION DES FICHIERS BINAIRES EN C ===\n\n");
    
    FILE *fichier_binaire;
    CompteBancaire compte1 = {101, "Alice Dupont", 1500.75};
    CompteBancaire compte2 = {102, "Bob Martin", 2300.50};
    CompteBancaire lecture_compte;
    
    // 1. Écriture dans un fichier binaire (mode "wb" - write binary)
    fichier_binaire = fopen("comptes.bin", "wb");
    if (fichier_binaire == NULL) {
        perror("Erreur lors de l'ouverture du fichier binaire en écriture");
        return 1;
    }
    
    fwrite(&compte1, sizeof(CompteBancaire), 1, fichier_binaire);
    fwrite(&compte2, sizeof(CompteBancaire), 1, fichier_binaire);
    fclose(fichier_binaire);
    printf("1. Fichier 'comptes.bin' créé et données binaires écrites.\n");
    
    // 2. Lecture d'un fichier binaire (mode "rb" - read binary)
    fichier_binaire = fopen("comptes.bin", "rb");
    if (fichier_binaire == NULL) {
        perror("Erreur lors de l'ouverture du fichier binaire en lecture");
        return 1;
    }
    
    printf("\n2. Lecture des données binaires de 'comptes.bin':\n");
    
    // Lire le premier compte
    fread(&lecture_compte, sizeof(CompteBancaire), 1, fichier_binaire);
    printf("   Compte 1 - ID: %d, Nom: %s, Solde: %.2f\n", 
           lecture_compte.id, lecture_compte.nom, lecture_compte.solde);
           
    // Lire le deuxième compte
    fread(&lecture_compte, sizeof(CompteBancaire), 1, fichier_binaire);
    printf("   Compte 2 - ID: %d, Nom: %s, Solde: %.2f\n", 
           lecture_compte.id, lecture_compte.nom, lecture_compte.solde);
           
    fclose(fichier_binaire);
    
    // 3. Suppression du fichier binaire
    if (remove("comptes.bin") == 0) {
        printf("\n3. Fichier 'comptes.bin' supprimé avec succès.\n");
    } else {
        perror("Erreur lors de la suppression du fichier binaire");
    }
    
    return 0;
}
