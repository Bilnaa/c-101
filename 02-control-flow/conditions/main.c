// Conditions en C

#include <stdio.h>

int main() {
    printf("=== STRUCTURES DE CONTRÔLE - CONDITIONS ===\n\n");
    
    int age = 20;
    float note = 15.5;
    char grade = 'B';
    
    // 1. Instruction if simple
    printf("1. INSTRUCTION IF SIMPLE:\n");
    if (age >= 18) {
        printf("   Vous êtes majeur (âge: %d)\n", age);
    }
    
    // 2. Instruction if-else
    printf("\n2. INSTRUCTION IF-ELSE:\n");
    if (note >= 10) {
        printf("   Félicitations ! Vous avez réussi (note: %.1f)\n", note);
    } else {
        printf("   Vous devez repasser l'examen (note: %.1f)\n", note);
    }
    
    // 3. Instruction if-else if-else
    printf("\n3. INSTRUCTION IF-ELSE IF-ELSE:\n");
    if (note >= 16) {
        printf("   Excellent ! (note: %.1f)\n", note);
    } else if (note >= 14) {
        printf("   Très bien ! (note: %.1f)\n", note);
    } else if (note >= 12) {
        printf("   Bien ! (note: %.1f)\n", note);
    } else if (note >= 10) {
        printf("   Assez bien ! (note: %.1f)\n", note);
    } else {
        printf("   Insuffisant ! (note: %.1f)\n", note);
    }
    
    // 4. Conditions imbriquées
    printf("\n4. CONDITIONS IMBRIQUÉES:\n");
    if (age >= 18) {
        if (note >= 12) {
            printf("   Vous pouvez accéder à l'université\n");
        } else {
            printf("   Vous êtes majeur mais votre note est insuffisante\n");
        }
    } else {
        printf("   Vous êtes mineur, vous ne pouvez pas encore accéder à l'université\n");
    }
    
    // 5. Opérateurs logiques
    printf("\n5. OPÉRATEURS LOGIQUES:\n");
    int temperature = 25;
    int humidite = 60;
    
    // ET logique (&&)
    if (temperature > 20 && humidite < 70) {
        printf("   Conditions météo agréables (temp: %d°C, humidité: %d%%)\n", temperature, humidite);
    }
    
    // OU logique (||)
    if (temperature > 30 || humidite > 80) {
        printf("   Conditions météo difficiles\n");
    }
    
    // NON logique (!)
    if (!(age < 16)) {
        printf("   Vous pouvez travailler (âge: %d)\n", age);
    }
    
    // 6. Opérateur ternaire
    printf("\n6. OPÉRATEUR TERNAIRE:\n");
    char *statut = (age >= 18) ? "majeur" : "mineur";
    printf("   Statut: %s\n", statut);
    
    // 7. Comparaisons multiples
    printf("\n7. COMPARAISONS MULTIPLES:\n");
    int nombre = 15;
    if (nombre >= 10 && nombre <= 20) {
        printf("   Le nombre %d est dans la plage [10, 20]\n", nombre);
    }
    
    return 0;
}
