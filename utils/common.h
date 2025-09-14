#ifndef COMMON_H
#define COMMON_H

// Headers communs pour tous les exemples
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>

// Macros utiles
#define MAX_SIZE 100
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

// Fonctions utilitaires communes
void print_separator(const char* title);
void print_array(int arr[], int size);
void clear_input_buffer(void);

// Implémentation des fonctions utilitaires
void print_separator(const char* title) {
    printf("\n=== %s ===\n", title);
}

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif // COMMON_H
