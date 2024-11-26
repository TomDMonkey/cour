#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int minimum(int* tab, int debut, int fin){
    int min = debut;
    for(int i = debut+1; i<fin; i++){
        if(tab[min] > tab[i]){
            min = i;
        }
    }
    return min;
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
        if (fin > taille) fin = taille;  triSelection(tab, debut, fin);
    }
}
void AfficherTab(int* tab, int taille){
    printf("[%d",tab[0]);
    for(int i = 1; i<taille; i++){
        printf(",%d",tab[i]);
    }
    printf("]\n");
}

void generer_alea(int* tab, int n, int m){
    srand( time( NULL ) );
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            tab[i*m+j] = rand()%101;
        }
    }
}


void remplir_tab(int* tab_mat, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            tab_mat[i*n+j] = n*i+j;
        }
    }
}


void transpos(int *t, int n){

for(int i=0; i< n-1; i++){



}

}

// int tmp;
// for(i=0;i<n; i++){
// tmp=tab[a*n+i];
// tab[a*n+i] = tab[b*n+i];
// tab[b*n+i]=tmp;
// }


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
//  generer_alea(D, n, m);
//     tri_ligne(D, n, m);
//     AfficherTab(D, n*m);









    fre(A);
    free(B);
    free(C);
    free(D);




}