#include <stdlib.h>
#include <stdio.h>

struct noeud{
    int val;
    struct noeud *fg;
    struct noeud *fd;
};/* Infixes */

void ppgi (struct noeud *r){
    if(r != NULL){
        ppgi(r->fg);
        printf("%d ", r->val);
        ppgi(r->fd);
    }
}

void ppdi (struct noeud *r){
    if(r != NULL){
        ppgi(r->fd);
        printf("%d ", r->val);
        ppgi(r->fg);
    }
}

                        /* Prefixe */

void ppg_pre(struct noeud *r){
    if(r != NULL){
        printf("%d ", r->val);
        ppg_pre(r->fg);
        ppg_pre(r->fd);
    }
}

void ppd_pre(struct noeud *r){
    if(r != NULL){
        printf("%d ", r->val);
        ppd_pre(r->fd);
        ppd_pre(r->fg);
    }
}

                        /* Postfixe */

void ppg_post(struct noeud *r){
    if(r != NULL){
        ppg_post(r->fg);
        ppg_post(r->fd);
        printf("%d ", r->val);
    }
}

void ppd_post(struct noeud *r){
    if(r != NULL){
        ppd_post(r->fd);
        ppd_post(r->fg);
        printf("%d ", r->val);
    }
}



int main(){
    struct noeud *a, *b, *c, *d, *e;

    a = (struct noeud*)malloc(sizeof(struct noeud));
    b = (struct noeud*)malloc(sizeof(struct noeud));
    c = (struct noeud*)malloc(sizeof(struct noeud));
    d = (struct noeud*)malloc(sizeof(struct noeud));
    e = (struct noeud*)malloc(sizeof(struct noeud));


    a->fg = NULL;
    a->fd = d;
    a->val = 17;

    b->fg = a;
    b->val = 3;

    c->fg = e;
    c->fd = NULL;
    c->val = 4;

    b->fd = c;

    d->fg = NULL;
    d->fd = NULL;
    d->val = 7;

    e->fg = NULL;
    e->fd = NULL;
    e->val = 13;


    printf("Parcours en Profondeur Infixe Gauche :\n");
    ppgi(b);
    printf("\n");

    printf("Parcours en Profondeur Infixe Droit :\n");
    ppdi(b);
    printf("\n");

    printf("Parcours en Profondeur Prefixe Gauche :\n");
    ppg_pre(b);
    printf("\n");

    printf("Parcours en Profondeur Prefixe Droit :\n");
    ppd_pre(b);
    printf("\n");

    printf("Parcours en Profondeur Postfixe Gauche :\n");
    ppg_post(b);
    printf("\n");

    printf("Parcours en Profondeur Postfixe Droit :\n");
    ppd_post(b);
    printf("\n");
}