#include <stdio.h>   // Inclusion de la bibliothèque standard pour l'entrée/sortie (fonctions printf, etc.)
#include <stdlib.h>  // Inclusion de la bibliothèque standard pour l'allocation de mémoire dynamique (malloc, free)

void fusion(int *tab, int taille, int m) {
    // Fonction qui fusionne deux parties d'un tableau déjà trié
    // 'tab' est le tableau à fusionner
    // 'taille' est la taille totale du tableau
    // 'm' est l'indice où se termine la première sous-partie triée

    int i = 0, j = m + 1, k = 0;  // Initialisation des indices: i pour la première partie, j pour la seconde partie, k pour tmp
    int *tmp = (int *)malloc(taille * sizeof(int));  // Allocation dynamique d'un tableau temporaire de la taille de 'tab'

    // Boucle pour parcourir et fusionner les deux sous-parties du tableau
    while (i <= m && j < taille) {  // Tant qu'il y a des éléments dans les deux sous-parties
        if (tab[i] < tab[j]) {  // Si l'élément de la première partie est plus petit que celui de la seconde
            tmp[k++] = tab[i++];  // Copier l'élément de la première partie dans 'tmp' et incrémenter i et k
        } else {  // Sinon, copier l'élément de la seconde partie
            tmp[k++] = tab[j++];  // Copier l'élément de la seconde partie dans 'tmp' et incrémenter j et k
        }
    }

    // Si tous les éléments de la première partie ont été copiés
    if (i > m) {
        for (; j < taille; j++) {  // Copier le reste des éléments de la seconde partie
            tmp[k++] = tab[j];  // Incrémenter j et copier les éléments restants
        }
    } else {  // Sinon, il reste des éléments dans la première partie
        for (; i <= m; i++) {  // Copier le reste des éléments de la première partie
            tmp[k++] = tab[i];  // Incrémenter i et copier les éléments restants
        }
    }

    // Copier les éléments triés du tableau temporaire 'tmp' vers le tableau d'origine 'tab'
    for(i = 0; i < taille; i++) {
        tab[i] = tmp[i];  // Remplacer les éléments de 'tab' par ceux triés dans 'tmp'
    }
    
    free(tmp);  // Libérer la mémoire allouée pour 'tmp' après utilisation
}

void affiche(int *tab, int taille, int m) {
    // Fonction qui affiche le tableau après l'avoir fusionné
    fusion(tab, taille, m);  // Appeler la fonction fusion pour trier les deux parties du tableau

    printf("Tableau fusionné : ");  // Message pour indiquer que le tableau est fusionné
    for (int i = 0; i < taille; i++) {  // Boucle pour afficher chaque élément du tableau
        printf("%d ", tab[i]);  // Affichage de l'élément courant
    }
    printf("\n");  // Saut de ligne après l'affichage du tableau
}

int main() {
    // Fonction principale qui exécute le programme

    int tab[] = {1, 4, 9, 17, 20, 50, 2, 4, 13, 21, 42, 100};  // Tableau à trier par fusion de deux parties
    int taille = 12;  // Taille du tableau
    int m = 5;  // Indice où se termine la première sous-partie triée

    affiche(tab, taille, m);  // Appeler la fonction 'affiche' pour fusionner et afficher le tableau

    return 0;  // Fin du programme
}
