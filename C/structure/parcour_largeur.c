#include <stdlib.h>
#include <stdio.h>

struct maillon {
    int val;
    struct maillon *suivant;
};

struct file {
    struct maillon* tete;
    struct maillon* queue;

};



void enfile(struct file* f, int e) {
    struct maillon* ptr = (struct maillon*)malloc(sizeof(struct maillon));
    if (ptr == NULL) {
        exit(1);
    }
    ptr->val = e;
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

int defile(struct file* f) {
    if (f->tete == NULL) {
        printf("Attention, file vide\n");
        exit(1);
    }

    struct maillon* tmp = f->tete;
    int val = tmp->val;
    
    // Si il n'y a qu'un seul élément dans la file
    if (f->tete == f->queue) {
        f->tete = NULL;
        f->queue = NULL;
    } else {
        f->tete = f->tete->suivant;
    }
    free(tmp);
    return val;
}

// Affiche les éléments de la liste
void affiche(struct maillon* f) {
    while (f != NULL) {
        printf("%d ", f->val);
        f = f->suivant;
    }
    printf("\n");
}

int main() {
    struct file f = {NULL, NULL};  
    struct maillon* liste = NULL;
   
    enfile(&f, 4);
    enfile(&f, 5);
    enfile(&f, 7);

    printf("File après enfile:\n");         
    affiche(f.tete);

    int elem = defile(&f);
    printf("Élément défilé: %d\n", elem);

    printf("File après defile:\n");
    affiche(f.tete);

    return 0;
}
