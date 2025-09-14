// 05-arrays-strings/strings/main.c

#include <stdio.h>
#include <string.h> // Pour les fonctions de manipulation de chaînes

int main() {
    printf("=== CHAÎNES DE CARACTÈRES EN C ===\n\n");
    
    // Déclaration et initialisation de chaînes de caractères
    char salutation[] = "Bonjour"; // Tableau de caractères modifiable
    char *message = "Hello World!"; // Pointeur vers une chaîne constante
    
    printf("1. Affichage des chaînes:\n");
    printf("   Salutation: %s\n", salutation);
    printf("   Message: %s\n", message);
    
    // Accès aux caractères
    printf("   Premier caractère de salutation: %c\n", salutation[0]);
    printf("   Cinquième caractère de message: %c\n", *(message + 4));
    
    // 2. Fonctions de manipulation de chaînes (string.h)
    printf("\n2. Fonctions de manipulation:\n");
    
    // strlen: Longueur de la chaîne
    printf("   Longueur de 'salutation': %zu\n", strlen(salutation));
    
    // strcpy: Copier une chaîne
    char destination[20];
    strcpy(destination, salutation);
    printf("   Chaîne copiée: %s\n", destination);
    
    // strcat: Concaténer des chaînes
    char str1[50] = "Hello";
    char str2[] = " World";
    strcat(str1, str2);
    printf("   Chaîne concaténée: %s\n", str1);
    
    // strcmp: Comparer des chaînes
    char s1[] = "Pomme";
    char s2[] = "Poire";
    char s3[] = "Pomme";
    printf("   Comparaison 'Pomme' et 'Poire': %d (différent de 0 si différentes)\n", strcmp(s1, s2));
    printf("   Comparaison 'Pomme' et 'Pomme': %d (0 si identiques)\n", strcmp(s1, s3));
    
    // snprintf: Formater une chaîne (sécurisé)
    char buffer[100];
    int age = 30;
    snprintf(buffer, sizeof(buffer), "Je m'appelle %s et j'ai %d ans.", "Alice", age);
    printf("   Chaîne formatée: %s\n", buffer);
    
    return 0;
}
