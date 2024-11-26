 #include <stdlib.h>
#include <stdio.h>

// Définition de la structure d'un maillon
struct maillon {
    int val;
    struct maillon *suivant;
};



// Vérifie si la liste est vide
int liste_vide(struct maillon *l) {
    return l == NULL;
}


// Ajoute un élément au début de la liste
struct maillon* ajout(struct maillon *l, int nombre) {
    struct maillon *ptr = (struct maillon*)malloc(sizeof(struct maillon));
    if (ptr == NULL) {
        exit(1);
    }
    ptr->val = nombre; 
    ptr->suivant = l;
    return ptr;
}

// Ajoute un élément à la fin de la liste
struct maillon* ajout_queue(struct maillon *l, int nombre) {
    struct maillon *ptr = (struct maillon*)malloc(sizeof(struct maillon));
    if (ptr == NULL) {
        exit(1);
    }
    
    ptr->val = nombre;
    ptr->suivant = NULL;

    if (l == NULL) {
        return ptr;
    }

    struct maillon *current = l;
    while (current->suivant != NULL) {
        current = current->suivant;
    }
    current->suivant = ptr;
    return l;
}

// Ajoute un élément de manière triée dans la liste (la liste doit etre imperativement trié au prealable sinon kaboom)
struct maillon* ajout_trie(struct maillon *l, int b) {
    struct maillon *ptr = l, *pred = NULL;
    struct maillon *new = (struct maillon*)malloc(sizeof(struct maillon));
    if (new == NULL) {
        exit(1); 
    }
    
    new->val = b;
    new->suivant = NULL;

    // Parcours de la liste pour trouver l'emplacement de l'insertion
    while (ptr != NULL && ptr->val < b) {
        pred = ptr;
        ptr = ptr->suivant;
    }

    // Insertion en tête si pred est NULL
    if (pred == NULL) {
        new->suivant = l;
        return new;
    }

    // Insertion après le prédécesseur
    pred->suivant = new;
    new->suivant = ptr;

    return l;
}

// maniere recursif
struct maillon* ajout_trie_R(struct maillon *l, int b) {
struct maillon* new;

if(l==NULL){
    new=(struct maillon *)malloc(sizeof(struct maillon));
    new->val = b;
    new ->suivant =NULL;
    return new;
}
if (b<l->val){
    new=(struct maillon *)malloc(sizeof(struct maillon));
    new->val = b;
    new ->suivant =l;
    return new;

}
l->suivant=ajout_trie_R(l->suivant, b);
return l;
}


// Supprime un élément avec une valeur donnée de la liste
struct maillon* supprimer(struct maillon *l, int e) {
    struct maillon *ptr = l, *pred = NULL;
    while (ptr != NULL && ptr->val != e) {
        pred = ptr;
        ptr = ptr->suivant;
    }
    if (ptr != NULL) {
        if (pred == NULL) {
            l = ptr->suivant;
        } else {
            pred->suivant = ptr->suivant;
        }
        free(ptr);
    }
    return l;
}

// Affiche les éléments de la liste dans l'ordre
void affiche(struct maillon *l) {
    while (l != NULL) {
        printf("%d ", l->val);
        l = l->suivant;
    }
    printf("\n");
}

// Calcule la somme des éléments de la liste
int somme(struct maillon *l) {
    int sum = 0;
    while (l != NULL) {
        sum += l->val;
        l = l->suivant;
    }
    return sum;
}

// Supprime la tête de la liste
struct maillon* suppression(struct maillon *l) {
    if (l != NULL) {
        struct maillon *tmp = l->suivant;
        free(l);
        l = tmp;
    }
    return l;
}





int main() {
    struct maillon *l = NULL; 

    // Ajout de plusieurs éléments à la liste
    l = ajout(l, 48);
    l = ajout(l, 35);
    l = ajout(l, 31);
    l = ajout(l, 8);
    l = ajout(l, 6);
    l = ajout(l, 3);
    
    printf("Liste :\n");
    affiche(l);

    // Suppression de la tête de la liste
    l = suppression(l);
    printf("Liste après suppression de la tête :\n");
    affiche(l);

    // Suppression d'un élément spécifique
    l = supprimer(l, 6);
    printf("Liste après suppression de 6 :\n");
    affiche(l);

    // Ajout d'un élément à la fin
    l = ajout_queue(l, 55);
    printf("Liste après ajout en queue :\n");
    affiche(l);

    // Calcul et affichage de la somme des éléments
    printf("La somme est : %d\n", somme(l));

    // Ajout d'éléments de manière triée
    l = ajout_trie(l, 2);
    l = ajout_trie(l, 20);
    l = ajout_trie(l, 1);
    printf("Liste après ajout trié :\n");
    affiche(l);
    //recursife
     l = ajout_trie_R(l, 3);
    l = ajout_trie_R(l, 21);
    l = ajout_trie_R(l, 56);
    printf("Liste après ajout trié recursife :\n");
    affiche(l);






    // Vidage de la liste
    while (!liste_vide(l)) {
        l = suppression(l);
    }

    return 0;
}





