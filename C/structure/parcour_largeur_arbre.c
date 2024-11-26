#include <stdlib.h>
#include <stdio.h>

struct maillon {
    struct noeud* arbre; // Modifier le type pour stocker un nœud de l'arbre
    struct maillon* suivant;
};

struct file {
    struct maillon* tete;
    struct maillon* queue;
};

struct noeud {
    int val;
    struct noeud* fg;
    struct noeud* fd;
};

void enfile(struct file* f, struct noeud* e) {
    struct maillon* ptr = (struct maillon*)malloc(sizeof(struct maillon));
    if (ptr == NULL) {
        exit(1);
    }
    ptr->arbre = e; // Stocker le nœud de l'arbre
    ptr->suivant = NULL;

    if (f->queue != NULL) {
        f->queue->suivant = ptr;
        f->queue = ptr;
    } else {
        // Si la file est vide
        f->tete = ptr;
        f->queue = ptr;
    }
}

struct noeud* defile(struct file* f) {
    if (f->tete == NULL) {
        printf("Attention, file vide\n");
        exit(1);
    }

    struct maillon* tmp = f->tete;
    struct noeud* val = tmp->arbre; // Récupérer le nœud de l'arbre

    // Si il n'y a qu'un seul élément dans la file
    if (f->tete == f->queue) {
        f->tete = NULL;
        f->queue = NULL;
    } else {
        f->tete = f->tete->suivant;
    }
    free(tmp);
    return val; // Retourner le nœud
}

void parcours_largeur(struct noeud* racine) {
    struct file f = {NULL, NULL}; // initialiser la file
    enfile(&f, racine); // Enfiler la racine

    while (f.tete != NULL) {
        struct noeud* courant = defile(&f); // Défile le nœud

        // afficher la valeur du nœud
        printf("%d ", courant->val);

        // enfiler les enfants gauche et droit
        if (courant->fg != NULL) {
            enfile(&f, courant->fg);
        }
        if (courant->fd != NULL) {
            enfile(&f, courant->fd);
        }
    }
}

int main() {
    struct noeud* a = (struct noeud*)malloc(sizeof(struct noeud));
    struct noeud* b = (struct noeud*)malloc(sizeof(struct noeud));
    struct noeud* c = (struct noeud*)malloc(sizeof(struct noeud));
    struct noeud* d = (struct noeud*)malloc(sizeof(struct noeud));
    struct noeud* e = (struct noeud*)malloc(sizeof(struct noeud));
    struct noeud* f = (struct noeud*)malloc(sizeof(struct noeud));

    // Construction de l'arbre
    a->fg = NULL;
    a->fd = d;
    a->val = 4;

    b->fg = a;
    b->fd = c;
    b->val = 17;

    c->fg = e;
    c->fd = NULL;
    c->val = 9;

    d->fg = f;
    d->fd = NULL;
    d->val = 21;

    e->fg = NULL;
    e->fd = NULL;
    e->val = 12;

    f->fg = NULL;
    f->fd = NULL;
    f->val = 0;


    // Afficher le parcours en largeur
    printf("Parcours en Largeur :\n");
    parcours_largeur(b);
    printf("\n");
}
