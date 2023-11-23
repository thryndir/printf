#include <stdio.h>
#include <stdarg.h>

// Fonction qui calcule la somme d'une liste variable d'entiers
int calculerSomme(int nombre_args, ...) {
    // Déclaration de la liste d'arguments variables
    va_list ap;

    // Initialisation de la liste d'arguments
    va_start(ap, nombre_args);

    // Variable pour stocker la somme
    int somme = 0;

    // Parcours de la liste d'arguments
    for (int i = 0; i < nombre_args; ++i) {
        // Utilisation de va_arg pour extraire chaque argument
        int valeur = va_arg(ap, int);

        // Ajout de la valeur à la somme
        somme += valeur;
    }

    // Fermeture de la liste d'arguments
    va_end(ap);

    // Retourne la somme calculée
    return somme;
}

int main() {
    // Appel de la fonction avec différents nombres d'arguments
    printf("Somme : %d\n", calculerSomme(3, 10, 20, 30));
    printf("Somme : %d\n", calculerSomme(5, 1, 2, 3, 4, 5));

    return 0;
}
