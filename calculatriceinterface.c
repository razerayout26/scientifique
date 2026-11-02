#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Fonction pour afficher le menu principal avec l'état de la mémoire
void afficherMenu(double memoire) {
    printf("\n=========================================\n");
    printf("         CALCULATRICE SCIENTIFIQUE       \n");
    printf("=========================================\n");
    printf(" [Mémoire actuelle : %.2lf]\n", memoire);
    printf("-----------------------------------------\n");
    printf(" 1. Addition (+)\n");
    printf(" 2. Soustraction (-)\n");
    printf(" 3. Multiplication (*)\n");
    printf(" 4. Division (/)\n");
    printf(" 5. Modulo (%%)\n");
    printf(" 6. Puissance (x^y)\n");
    printf(" 7. Racine carrée (sqrt)\n");
    printf(" 8. Sinus (sin)\n");
    printf(" 9. Cosinus (cos)\n");
    printf("-----------------------------------------\n");
    printf(" 10. Rappeler la mémoire (MR)\n");
    printf(" 11. Ajouter à la mémoire (M+)\n");
    printf(" 12. Effacer la mémoire (MC)\n");
    printf("  0. Quitter\n");
    printf("=========================================\n");
    printf("Votre choix : ");
}

// Fonction pour enregistrer le calcul dans un fichier texte
void enregistrerHistorique(const char *operation) {
    FILE *f = fopen("historique.txt", "a"); // Mode "append" pour ajouter à la fin du fichier
    if (f != NULL) {
        fprintf(f, "%s\n", operation);
        fclose(f);
    }
}

int main() {
    int choix;
    double a, b, resultat;
    double memoire = 0.0; // Initialisation de la mémoire à 0
    char ligneHistorique[150];

    do {
        afficherMenu(memoire);
        if (scanf("%d", &choix) != 1) {
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            while(getchar() != '\n'); // Vider le buffer
            continue;
        }

        if (choix == 0) {
            printf("Au revoir !\n");
            break;
        }

        // Gestion de la mémoire (pas besoin de saisir de nombres a ou b)
        if (choix == 10) {
            printf("Valeur en mémoire : %.2lf\n", memoire);
            continue;
        } else if (choix == 11) {
            printf("Entrez la valeur à ajouter en mémoire : ");
            scanf("%lf", &a);
            memoire += a;
            printf("Mémoire mise à jour : %.2lf\n", memoire);
            continue;
        } else if (choix == 12) {
            memoire = 0.0;
            printf("Mémoire effacée (MC).\n");
            continue;
        }

        // Gestion des choix nécessitant deux nombres
        if (choix >= 1 && choix <= 6) {
            printf("Entrez le premier nombre (a) : ");
            scanf("%lf", &a);
            printf("Entrez le second nombre (b) : ");
            scanf("%lf", &b);
        } 
        // Gestion de la racine carrée
        else if (choix == 7) {
            printf("Entrez le nombre : ");
            scanf("%lf", &a);
        }
        // Gestion de la trigonométrie (sin, cos) avec choix Degrés / Radians
        else if (choix == 8 || choix == 9) {
            int unite;
            printf("Entrez l'angle : ");
            scanf("%lf", &a);
            printf("Choisissez l'unité :\n 1. Radians\n 2. Degrés\nVotre choix : ");
            scanf("%d", &unite);
            if (unite == 2) {
                a = a * (M_PI / 180.0); // Conversion degrés -> radians
            }
        }

        // Traitement selon l'opération
        switch (choix) {
            case 1:
                resultat = a + b;
                printf("Résultat : %.2lf + %.2lf = %.2lf\n", a, b, resultat);
                sprintf(ligneHistorique, "%.2lf + %.2lf = %.2lf", a, b, resultat);
                enregistrerHistorique(ligneHistorique);
                break;
            case 2:
                resultat = a - b;
                printf("Résultat : %.2lf - %.2lf = %.2lf\n", a, b, resultat);
                sprintf(ligneHistorique, "%.2lf - %.2lf = %.2lf", a, b, resultat);
                enregistrerHistorique(ligneHistorique);
                break;
            case 3:
                resultat = a * b;
                printf("Résultat : %.2lf * %.2lf = %.2lf\n", a, b, resultat);
                sprintf(ligneHistorique, "%.2lf * %.2lf = %.2lf", a, b, resultat);
                enregistrerHistorique(ligneHistorique);
                break;
            case 4:
                if (b == 0) {
                    printf("Erreur : Division par zéro impossible !\n");
                } else {
                    resultat = a / b;
                    printf("Résultat : %.2lf / %.2lf = %.2lf\n", a, b, resultat);
                    sprintf(ligneHistorique, "%.2lf / %.2lf = %.2lf", a, b, resultat);
                    enregistrerHistorique(ligneHistorique);
                }
                break;
            case 5:
                if ((int)b == 0) {
                    printf("Erreur : Modulo par zéro impossible !\n");
                } else {
                    int mod = (int)a % (int)b;
                    printf("Résultat : %d %% %d = %d\n", (int)a, (int)b, mod);
                    sprintf(ligneHistorique, "%d %% %d = %d", (int)a, (int)b, mod);
                    enregistrerHistorique(ligneHistorique);
                }
                break;
            case 6:
                resultat = pow(a, b);
                printf("Résultat : %.2lf ^ %.2lf = %.2lf\n", a, b, resultat);
                sprintf(ligneHistorique, "%.2lf ^ %.2lf = %.2lf", a, b, resultat);
                enregistrerHistorique(ligneHistorique);
                break;
            case 7:
                if (a < 0) {
                    printf("Erreur : Racine carrée d'un nombre négatif impossible !\n");
                } else {
                    resultat = sqrt(a);
                    printf("Résultat : sqrt(%.2lf) = %.2lf\n", a, resultat);
                    sprintf(ligneHistorique, "sqrt(%.2lf) = %.2lf", a, resultat);
                    enregistrerHistorique(ligneHistorique);
                }
                break;
            case 8:
                resultat = sin(a);
                printf("Résultat : sin = %.2lf\n", resultat);
                sprintf(ligneHistorique, "sin(angle) = %.2lf", resultat);
                enregistrerHistorique(ligneHistorique);
                break;
            case 9:
                resultat = cos(a);
                printf("Résultat : cos = %.2lf\n", resultat);
                sprintf(ligneHistorique, "cos(angle) = %.2lf", resultat);
                enregistrerHistorique(ligneHistorique);
                break;
            default:
                printf("Choix invalide.\n");
        }

    } while (choix != 0);

    return 0;
}