// Switch-Case en C

#include <stdio.h>

int main() {
    printf("=== STRUCTURES DE CONTRÔLE - SWITCH-CASE ===\n\n");
    
    int choix = 2;
    // 1. Switch-case simple
    printf("1. SWITCH-CASE SIMPLE:\n");
    switch (choix) {
        case 1:
            printf("   Vous avez choisi l'option 1\n");
            break;
        case 2:
            printf("   Vous avez choisi l'option 2\n");
            break;
        case 3:
            printf("   Vous avez choisi l'option 3\n");
            break;
        default:
            printf("   Vous avez choisi une option invalide\n");
            break;
    }
    return 0;
}