#include <stdlib.h>
#include <stdio.h>

// Liste doublement chaînée
struct D_maillon {
    int val;
    struct D_maillon *suivant;
    struct D_maillon *pred;
};

struct D_maillon *supp(struct D_maillon *l, struct D_maillon *ptr) {
    //algorythme  teta de 1
    if (ptr == NULL) {
        return l;
    }

    if (ptr == l) {
        l = ptr->suivant;
        if (l != NULL) {
            l->pred = NULL;
        }
        free(ptr);
        return l;
    }

    if (ptr->suivant == NULL) {
        ptr->pred->suivant = NULL;
    } else {
        ptr->pred->suivant = ptr->suivant;
        ptr->suivant->pred = ptr->pred;
    }
    free(ptr);
    return l;
}

struct D_maillon *ajouter(struct D_maillon *l, int val) {
    struct D_maillon *ptr = (struct D_maillon*)malloc(sizeof(struct D_maillon));
    ptr->val = val;
    ptr->suivant = l;
    ptr->pred = NULL;
    if (l != NULL) {
        l->pred = ptr;
    }
    return ptr; // Retourne le nouveau maillon ajouté
}

void afficher(struct D_maillon *l) {
    struct D_maillon *ptr = l;
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->suivant;
    }
    printf("\n");
}

int main() {
    struct D_maillon *liste = NULL;

    liste = ajouter(liste, 10);
    liste = ajouter(liste, 20);
    liste = ajouter(liste, 30);
    afficher(liste);

    liste = supp(liste, liste->suivant); // Supprime le maillon suivant le premier maillon (20)
    afficher(liste);

    liste = supp(liste, liste); // Supprime le premier maillon (10)
    afficher(liste);

    liste = supp(liste, liste); // Supprime le dernier maillon (30)
    afficher(liste);

    return 0;
}
