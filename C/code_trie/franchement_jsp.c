#include <stdlib.h>
#include <stdio.h>
#include <time.h>



void generer_alea(int* tab, int n, int m){
    srand( time( NULL ) );
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            tab[i*m+j] = rand()%101;
        }
    }
}


void triSelection(int* tab, int debut, int fin){
    int imin;
    int tmp;
    for(int i = debut; i<fin; i++){
        imin = minimum(tab, i, fin);
        tmp = tab[imin];
        tab[imin] = tab[i];
        tab[i] = tmp;
    }
}




void tri_ligne(int* tab, int n, int m){
    int taille = n * m;
    for(int i = 0; i<n; i++){
        int debut = i * m;
        int fin = (i + 1) * m;
        if (fin > taille) fin = taille; // Assure que fin ne dépasse pas la taille du tableau
        triSelection(tab, debut, fin);
    }
}

void AfficherTab(int* tab, int taille){
    printf("[%d",tab[0]);
    for(int i = 1; i<taille; i++){
        printf(",%d",tab[i]);
    }
    printf("]\n");
}




int main(){
    int i;
    int n = 4;
    int m = 3;
    int* A;
    int* B;
    int* C;
    int* D;
    A = (int*)malloc((n*n)*sizeof(int));
    B = (int*)malloc((n*n)*sizeof(int));
    C = (int*)malloc((n*n)*sizeof(int));
    D = (int*)malloc((n*m)*sizeof(int));

    generer_alea(D, n, m);
    tri_ligne(D, n, m);
    AfficherTab(D, n*m);

    free(A);
    free(B);
    free(C);
    free(D);
}