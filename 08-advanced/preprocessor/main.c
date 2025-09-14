// 08-advanced/preprocessor/main.c

#include <stdio.h>

// 1. Macros simples
#define PI 3.14159
#define MESSAGE "Bonjour du préprocesseur!"

// 2. Macros avec arguments
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ADD(a, b) (a + b)

// 3. Inclusion de fichiers
// #include <stdio.h> est déjà fait

// 4. Compilation conditionnelle
#define DEBUG_MODE

int main() {
    printf("=== DIRECTIVES DU PRÉPROCESSEUR EN C ===\n\n");
    
    // Utilisation des macros simples
    printf("1. Macros simples:\n");
    printf("   La valeur de PI est: %.5f\n", PI);
    printf("   Message: %s\n", MESSAGE);
    
    // Utilisation des macros avec arguments
    printf("\n2. Macros avec arguments:\n");
    int x = 10, y = 20;
    printf("   Le maximum entre %d et %d est: %d\n", x, y, MAX(x, y));
    printf("   L'addition de %d et %d est: %d\n", x, y, ADD(x, y));
    
    // Compilation conditionnelle
    printf("\n3. Compilation conditionnelle:\n");
#ifdef DEBUG_MODE
    printf("   Mode DEBUG activé. Cette ligne est compilée.\n");
#else
    printf("   Mode DEBUG désactivé. Cette ligne n'est PAS compilée.\n");
#endif
    
    // #ifndef, #if, #elif, #else, #endif
    #if ADD(5,5) == 10
        printf("   5 + 5 est bien égal à 10.\n");
    #else
        printf("   Erreur de calcul.\n");
    #endif

    // 5. Opérateurs # et ##
    #define STRINGIFY(x) #x
    #define CONCAT(a, b) a##b

    printf("\n4. Opérateurs # et ##:\n");
    printf("   STRINGIFY(PI) : %s\n", STRINGIFY(PI)); // Convertit PI en "PI"
    int xy = CONCAT(x, y); // Devient int xy = xy;
    printf("   CONCAT(x, y) = %d (où x=10, y=20 devient xy = 1020)\n", xy);
    
    return 0;
}
