# scientifique
Le but de ce répertoire est de couvrir le fichier de projet scientifique pour mieux organiser le programme et organiser le code.

# Calculatrice Scientifique en C

Une calculatrice scientifique en ligne de commande développée en langage C. Ce projet permet d'effectuer des opérations arithmétiques de base ainsi que des fonctions mathématiques avancées.

## Fonctionnalités

* **Opérations de base :** Addition (`+`), Soustraction (`-`), Multiplication (`*`), Division (`/`) et Modulo (`%`).
* **Fonctions avancées :** Puissance ($x^y$), Racine carrée ($\sqrt{x}$), Sinus et Cosinus (en radians).
* **Interface interactive :** Boucle de calcul continue avec menu textuel et gestion des erreurs de saisie (division par zéro, nombres négatifs pour la racine, etc.).

---

## Prérequis

Pour compiler et exécuter ce programme, tu as besoin de :
* Un compilateur C (comme `gcc`).
* Un environnement compatible (Linux, macOS, ou Windows avec MinGW / WSL).

---

##  Installation et Compilation

1. **Cloner le dépôt ou télécharger le fichier source** `calculatrice.c` dans un dossier.
2. **Ouvrir un terminal** dans le dossier du projet.
3. **Compiler le programme** en pensant bien à lier la bibliothèque mathématique (`-lm`) :
   ```bash
   gcc calculatrice.c -o calculatrice -lm
