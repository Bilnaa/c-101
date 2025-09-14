# Script de bootstrap PowerShell pour compiler le système de build C-101

Write-Host "=== Bootstrap du système de build C-101 avec nob.h ===" -ForegroundColor Blue

# Détection du compilateur C
$CC = $null

if (Get-Command gcc -ErrorAction SilentlyContinue) {
    $CC = "gcc"
} elseif (Get-Command clang -ErrorAction SilentlyContinue) {
    $CC = "clang"
} elseif (Get-Command cl -ErrorAction SilentlyContinue) {
    $CC = "cl"
} else {
    Write-Host "❌ Erreur: Aucun compilateur C trouvé (gcc, clang, ou cl)" -ForegroundColor Red
    Write-Host "   Installez un compilateur C pour continuer" -ForegroundColor Red
    exit 1
}

Write-Host "🔍 Compilateur détecté: $CC" -ForegroundColor Green

# Compiler le système de build
Write-Host "🔨 Compilation du système de build..." -ForegroundColor Yellow

if ($CC -eq "cl") {
    # Microsoft Visual C++
    & $CC /Wall /std:c99 /Ivendor\nob.h build.c /Fe:build.exe
} else {
    # GCC/Clang
    & $CC -Wall -Wextra -std=c99 -g -Ivendor/nob.h -o build.exe build.c
}

if ($LASTEXITCODE -eq 0) {
    Write-Host "✅ Système de build compilé avec succès !" -ForegroundColor Green
    Write-Host ""
    Write-Host "🚀 Commandes disponibles:" -ForegroundColor Cyan
    Write-Host "  .\build.exe help              - Afficher l'aide"
    Write-Host "  .\build.exe list              - Lister tous les exemples"
    Write-Host "  .\build.exe all               - Compiler tous les exemples"
    Write-Host "  .\build.exe <nom>             - Compiler un exemple spécifique"
    Write-Host "  .\build.exe run-<nom>         - Exécuter un exemple"
    Write-Host "  .\build.exe clean             - Nettoyer les fichiers compilés"
    Write-Host ""
    Write-Host "💡 Essayez: .\build.exe help" -ForegroundColor Yellow
} else {
    Write-Host "❌ Erreur lors de la compilation du système de build" -ForegroundColor Red
    exit 1
}
