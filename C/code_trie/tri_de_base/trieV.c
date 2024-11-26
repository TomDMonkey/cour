// programme qui permet de mettre a gauche toute les valeurs inferieur a v

#include <stdio.h>


void plopV( int *t, int taille){

int i=0, j=taille-1,tmp;
int v= 2;


while(i<j){
        if(t[i]>=v){
            tmp=t[j];
            t[j]=t[i];
            t[i]=tmp;
            
            j--;
        }else i++;
}

}

void affiche(int *tab, int taille) {
    plopV(tab, taille);  

    printf("tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);  
    }
    printf("\n");
}

int main() {
    
    int tab[] = {3, 3, 1, 6, 5, 8, 9, 1, 7, 4};
    int taille = 10;  
    affiche(tab, taille); 
    return 0; 
}