#!/bin/bash
# Script de bootstrap cross-platform pour compiler le système de build C-101

set -e  # Exit on any error

echo "=== Bootstrap du système de build C-101 avec nob.h ==="

# Détection du compilateur C
if command -v gcc &> /dev/null; then
    CC="gcc"
elif command -v clang &> /dev/null; then
    CC="clang"
elif command -v cc &> /dev/null; then
    CC="cc"
else
    echo "❌ Erreur: Aucun compilateur C trouvé (gcc, clang, ou cc)"
    echo "   Installez un compilateur C pour continuer"
    exit 1
fi

echo "🔍 Compilateur détecté: $CC"

# Compiler le système de build
echo "🔨 Compilation du système de build..."
$CC -Wall -Wextra -std=c99 -g -Ivendor/nob.h -o build build.c

if [ $? -eq 0 ]; then
    echo "✅ Système de build compilé avec succès !"
    echo ""
    echo "🚀 Commandes disponibles:"
    echo "  ./build help              - Afficher l'aide"
    echo "  ./build list              - Lister tous les exemples"
    echo "  ./build all               - Compiler tous les exemples"
    echo "  ./build <nom>             - Compiler un exemple spécifique"
    echo "  ./build run-<nom>         - Exécuter un exemple"
    echo "  ./build clean             - Nettoyer les fichiers compilés"
    echo ""
    echo "💡 Essayez: ./build help"
else
    echo "❌ Erreur lors de la compilation du système de build"
    exit 1
fi
