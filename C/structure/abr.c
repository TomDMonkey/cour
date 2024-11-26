#include <stdlib.h>
#include <stdio.h>

struct noeud {
    int val;
    struct noeud *fg, *fd;
};

struct noeud* creer_noeud(int val) {
    struct noeud* nouveau = (struct noeud*)malloc(sizeof(struct noeud));
    nouveau->val = val;
    nouveau->fg = NULL;
    nouveau->fd = NULL;
    return nouveau;
}

struct noeud* ajout(struct noeud* r, int val) {
    if (r == NULL) {
        return creer_noeud(val);
    }
    if (val < r->val) {
        r->fg = ajout(r->fg, val);
    } else if (val > r->val) {
        r->fd = ajout(r->fd, val);
    }
    return r;
}

struct noeud* trouver_min(struct noeud* r) {
    while (r && r->fg != NULL) {
        r = r->fg;
    }
    return r;
}

struct noeud* suppression(struct noeud* r, int val) {
    if (r == NULL) {            
        return NULL;
    }
    if (val < r->val) {
        r->fg = suppression(r->fg, val);
    } else if (val > r->val) {
        r->fd = suppression(r->fd, val);
    } else {
        //  Le noeud est une feuille
        if (r->fg == NULL && r->fd == NULL) {
            free(r);
            return NULL;
        }
        //  Le noeud a un seul enfant
        if (r->fg == NULL) {
            struct noeud* temp = r->fd;
            free(r);
            return temp;
        } else if (r->fd == NULL) {     
            struct noeud* temp = r->fg;
            free(r);
            return temp;
        }
        //  Le noeud a deux enfants
        struct noeud* successeur = trouver_min(r->fd);
        r->val = successeur->val;
        r->fd = suppression(r->fd, successeur->val);
    }
    return r;
}

void ppgp(struct noeud* r) {
    if (r != NULL) {
        printf("%d ", r->val);
        ppgp(r->fg);
        ppgp(r->fd);
    }
}

int main() {
    struct noeud* r = NULL;
    r = ajout(r, 33);
    r = ajout(r, 19);
    r = ajout(r, 9);
    r = ajout(r, 4);
    r = ajout(r, 20);
    r = ajout(r, 23);
    r = ajout(r, 21);


    printf("Arbre avant suppression :\n");
    ppgp(r);
    printf("\n");

    r = suppression(r, 19);
    r = suppression(r, 21);
    printf("Arbre après suppression :\n");
    ppgp(r);
    printf("\n");

    return 0;
}
