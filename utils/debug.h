#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>

// Macros de debug
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
    #define DEBUG_PRINT_VAR(var, fmt) printf("[DEBUG] %s = " fmt "\n", #var, var)
#else
    #define DEBUG_PRINT(fmt, ...)
    #define DEBUG_PRINT_VAR(var, fmt)
#endif

// Macro pour afficher les informations d'une variable
#define PRINT_VAR_INFO(var, fmt) \
    printf("Variable: %s\n", #var); \
    printf("Valeur: " fmt "\n", var); \
    printf("Adresse: %p\n", &var); \
    printf("Taille: %zu octets\n\n", sizeof(var))

// Macro pour afficher les informations d'un pointeur
#define PRINT_PTR_INFO(ptr, fmt) \
    printf("Pointeur: %s\n", #ptr); \
    printf("Valeur pointée: " fmt "\n", *ptr); \
    printf("Adresse du pointeur: %p\n", &ptr); \
    printf("Adresse pointée: %p\n", ptr); \
    printf("Taille du pointeur: %zu octets\n\n", sizeof(ptr))

// Macro pour mesurer le temps d'exécution
#define TIME_EXECUTION(code) \
    do { \
        clock_t start = clock(); \
        code; \
        clock_t end = clock(); \
        double cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC; \
        printf("Temps d'exécution: %.6f secondes\n", cpu_time); \
    } while(0)

#endif // DEBUG_H
