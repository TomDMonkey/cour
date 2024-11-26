#include <stdio.h>

void insere(int *tab,int p){

int  i = p-1, e;

while(i >= 0 && tab[i]>e  ){
   tab[i+1] = tab[i];
    i--;

}
tab[i+1]=e;

}

void affiche(int *tab, int taille) {
    trie(tab, taille);  

    printf("tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);  
    }
    printf("\n");
}



int main() {
    
    int tab[] = {1,9,10,11,20,22,25,30,31,40};
    insere(tab, 10);
    affiche(tab, 10); 
    return 0; 
}
