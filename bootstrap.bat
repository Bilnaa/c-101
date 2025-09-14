@echo off
REM Script de bootstrap Windows pour compiler le système de build C-101

echo === Bootstrap du système de build C-101 avec nob.h ===

REM Détection du compilateur C
where gcc >nul 2>nul
if %errorlevel% == 0 (
    set CC=gcc
    goto :compiler_found
)

where clang >nul 2>nul
if %errorlevel% == 0 (
    set CC=clang
    goto :compiler_found
)

where cl >nul 2>nul
if %errorlevel% == 0 (
    set CC=cl
    goto :compiler_found
)

echo ❌ Erreur: Aucun compilateur C trouvé (gcc, clang, ou cl)
echo    Installez un compilateur C pour continuer
exit /b 1

:compiler_found
echo 🔍 Compilateur détecté: %CC%

REM Compiler le système de build
echo 🔨 Compilation du système de build...
if "%CC%" == "cl" (
    %CC% /Wall /std:c99 /Ivendor\nob.h build.c /Fe:build.exe
) else (
    %CC% -Wall -Wextra -std=c99 -g -Ivendor/nob.h -o build.exe build.c
)

if %errorlevel% == 0 (
    echo ✅ Système de build compilé avec succès !
    echo.
    echo 🚀 Commandes disponibles:
    echo   build.exe help              - Afficher l'aide
    echo   build.exe list              - Lister tous les exemples
    echo   build.exe all               - Compiler tous les exemples
    echo   build.exe ^<nom^>             - Compiler un exemple spécifique
    echo   build.exe run-^<nom^>         - Exécuter un exemple
    echo   build.exe clean             - Nettoyer les fichiers compilés
    echo.
    echo 💡 Essayez: build.exe help
) else (
    echo ❌ Erreur lors de la compilation du système de build
    exit /b 1
)
