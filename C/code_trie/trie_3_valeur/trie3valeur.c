// trie un tanleau avec un nombre donné d'info avec 3 valeur precise 

#include <stdlib.h>
#include <stdio.h>


int tri_jsp(int *tab,int taille){
    int i=0, f=taille-1, tmp, d=0;
    while(i<=f){
     if (tab[i] == 2){
        i++; 
    }
     else if (tab[i] == 1){
        tmp = tab[i];
        tab[i]=tab[d];
        tab[d]=tmp;
        i++;
        d++;
     }
     else if (tab[i]== 3){
        tmp =tab[i];
        tab[i]=tab[f];
        tab[f]=tmp;
        f--;
     }
     }

}

void affiche(int *tab, int taille) {
    tri_jsp(tab, taille);  

    printf("tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);  
    }
    printf("\n");
}



int main(){
    int tableau[] = {2,3,2,1,3,3,1,1,2};
    affiche(tableau, 9);
}