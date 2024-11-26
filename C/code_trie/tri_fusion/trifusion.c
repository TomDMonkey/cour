// trier coté gauche, puis droit, puis fusionner les deux


#include <stdlib.h>
#include <stdio.h>


void tri_fusion(int *t, int d, int taille){
int d=0, f=taille, milieu=(d+f)/2;


}




void affiche(int *tab, int taille) {
    tri_(tab, taille);  

    printf("tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);  
    }
    printf("\n");
}

int main(){
    int tableau[] = {5,6,2,-4,56,-11,6,3,4,52,-22,-65,7,1};
    affiche(tableau, 9);
}