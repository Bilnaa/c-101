# 04-pointers/deliberate-fail/ - Pointeur Pendant (Dangling Pointer)

Cette section démontre le concept d'un pointeur pendant (dangling pointer) en C, une erreur courante qui survient lorsque un pointeur pointe vers une mémoire qui a été libérée ou qui n'est plus valide.

## 📝 Explication

Un pointeur pendant est un pointeur qui pointe vers un emplacement mémoire qui a été désalloué ou qui n'est plus attribué au programme. Tenter de déréférencer un tel pointeur conduit à un **comportement indéfini** (Undefined Behavior - UB).

Dans l'exemple `main.c`:

1. La fonction `creerPointeurDangling()` déclare une variable locale `local_variable`.
2. Elle retourne l'adresse de cette variable locale.
3. Dès que `creerPointeurDangling()` se termine, `local_variable` est détruite (sa mémoire est désallouée de la pile d'exécution de la fonction).
4. Le pointeur `dangling_ptr` dans `main()` reçoit cette adresse, mais la mémoire qu'il pointe n'est plus valide.
5. Tenter de lire ou d'écrire à `*dangling_ptr` est un comportement indéfini. Le programme peut planter (erreur de segmentation), renvoyer une valeur inattendue, ou même sembler fonctionner correctement, ce qui rend ce type de bug difficile à détecter.

## ⚠️ Comportement Indéfini

Le comportement indéfini signifie que le compilateur et le système d'exploitation ne garantissent rien sur ce qui se passera. Cela peut inclure:
- Un crash immédiat du programme.
- Des données corrompues.
- Un comportement apparemment correct (par exemple, lire la dernière valeur dans cette zone mémoire) qui disparaît dans des conditions différentes.
- Des vulnérabilités de sécurité.

## 💡 Prévention

Pour éviter les pointeurs pendants:
- **Ne jamais retourner l'adresse d'une variable locale** d'une fonction.
- Après `free(ptr)`, toujours définir `ptr = NULL` pour éviter de déréférencer accidentellement la mémoire libérée.
- Être extrêmement prudent avec les pointeurs qui sont passés entre différentes fonctions et avec l'allocation/désallocation de mémoire dynamique.

## 📚 Ressources Complémentaires

- [Dangling Pointer in C/C++ - GeeksforGeeks](https://www.geeksforgeeks.org/dangling-pointer-in-c-cpp/)
- [Undefined Behavior in C - Wikipedia](https://en.wikipedia.org/wiki/Undefined_behavior)
