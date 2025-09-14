# C-101 : Apprentissage du Langage C

## 📚 Description

Ce repository contient une collection complète d'exemples et d'exercices pour apprendre le langage C de manière progressive et structurée. Chaque concept est illustré par des exemples pratiques avec des commentaires détaillés en français.

## 🗂️ Structure du Repository

### 01-basics/ - Concepts Fondamentaux
- **hello-world/** : Premier programme C
- **variables/** : Déclaration et utilisation des variables
- **data-types/** : Types de données en C

### 02-control-flow/ - Structures de Contrôle
- **conditions/** : Instructions if/else
- **loops/** : Boucles for, while, do-while
- **switch-case/** : Instructions switch

### 03-functions/ - Fonctions
- **basic-functions/** : Définition et appel de fonctions
- **recursion/** : Fonctions récursives
- **function-pointers/** : Pointeurs de fonctions

### 04-pointers/ - Pointeurs
- **basic-pointers** : Concepts de base des pointeurs
- **deliberate-fail** : Pointeur pendant (dangling pointer) et comportement indéfini
- **pointer-arithmetic/** : Arithmétique des pointeurs
- **dynamic-memory/** : Allocation dynamique de mémoire
- **pointer-functions/** : Pointeurs et fonctions

### 05-arrays-strings/ - Tableaux et Chaînes
- **arrays/** : Tableaux unidimensionnels et multidimensionnels
- **strings/** : Manipulation des chaînes de caractères
- **multidimensional/** : Tableaux multidimensionnels

### 06-structures/ - Structures et Unions
- **basic-structs/** : Structures de base
- **nested-structs/** : Structures imbriquées
- **unions/** : Unions en C

### 07-file-io/ - Entrées/Sorties Fichiers
- **text-files/** : Lecture et écriture de fichiers texte
- **binary-files/** : Fichiers binaires
- **file-management/** : Gestion des fichiers

### 08-advanced/ - Concepts Avancés
- **preprocessor/** : Directives du préprocesseur
- **bitwise-operations/** : Opérations bit à bit
- **error-handling/** : Gestion d'erreurs

### 09-projects/ - Projets Pratiques
- **calculator/** : Calculatrice simple
- **student-management/** : Système de gestion d'étudiants
- **file-manager/** : Gestionnaire de fichiers

### utils/ - Utilitaires
- **common.h** : Headers communs
- **debug.h** : Macros de debug
- **examples/** : Exemples supplémentaires

## 🚀 Compilation et Exécution

### Système de Build avec nob.h

Ce projet utilise [nob.h](https://github.com/tsoding/nob.h), une bibliothèque header-only pour écrire des recettes de build en C pur, qui va nous permettre de nous libérer de make. Mais attention ce n'est pas pour le professionel.

#### Bootstrap du système de build

**Linux/macOS:**
```bash
./bootstrap.sh
```

**Windows (Command Prompt):**
```cmd
bootstrap.bat
```

**Windows (PowerShell):**
```powershell
.\bootstrap.ps1
```

Le script détecte automatiquement le compilateur disponible (gcc, clang, ou cl) et compile le système de build.

#### Commandes disponibles
```bash
# Linux/macOS
./build help              # Afficher l'aide
./build list              # Lister tous les exemples
./build all               # Compiler tous les exemples
./build <nom>             # Compiler un exemple spécifique
./build run-<nom>          # Exécuter un exemple
./build clean             # Nettoyer les fichiers compilés

# Windows
build.exe help            # Afficher l'aide
build.exe list            # Lister tous les exemples
build.exe all             # Compiler tous les exemples
build.exe <nom>           # Compiler un exemple spécifique
build.exe run-<nom>        # Exécuter un exemple
build.exe clean           # Nettoyer les fichiers compilés
```

#### Exemples d'utilisation
```bash
# Linux/macOS
./build all                    # Compiler tous les exemples
./build hello-world           # Compiler un exemple spécifique
./build run-hello-world       # Exécuter un exemple
./build run-pointers-showcase # Exécuter un autre exemple

# Windows
build.exe all                 # Compiler tous les exemples
build.exe hello-world         # Compiler un exemple spécifique
build.exe run-hello-world     # Exécuter un exemple
build.exe run-pointers-showcase # Exécuter un autre exemple
```

### Compilation manuelle (alternative)
```bash
gcc nom_du_fichier.c -o executable
./executable
```

## 📖 Comment Utiliser ce Repository

1. **Commencez par les bases** : Suivez l'ordre numérique des dossiers
2. **Lisez les README** : Chaque section a sa propre documentation
3. **Compilez et exécutez** : Testez chaque exemple
4. **Modifiez le code** : Expérimentez avec les exemples
5. **Passez aux projets** : Appliquez vos connaissances

## 🎯 Objectifs Pédagogiques

- Comprendre les concepts fondamentaux du C
- Maîtriser la gestion de la mémoire
- Développer des compétences en programmation système
- Apprendre les bonnes pratiques de programmation

## 📝 Prérequis

- Connaissance de base en programmation (recommandé)
- Compilateur GCC installé
- Éditeur de texte ou IDE

## 🤝 Contribution

Ce repository est conçu pour l'apprentissage. N'hésitez pas à :
- Ajouter de nouveaux exemples
- Améliorer la documentation
- Corriger les erreurs
- Proposer de nouveaux projets

## 📄 Licence

Ce projet est sous licence MIT. Voir le fichier LICENSE pour plus de détails.

---
