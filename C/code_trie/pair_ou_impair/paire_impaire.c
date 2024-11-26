//  a gauche les paires a droite les impaires ou l'inverse je sais plus


#include <stdio.h>


void paire_impaire( int *t, int taille){

int i=0, j=taille,tmp;

while(i!=j){
        if(t[i]%2!=0 && t[j]%2==0){
            tmp=t[i];
            t[i]=t[j];
            t[j]=tmp;
            j--;
            }else{
                j--;
            }
        if(t[i]%2==0 && t[j]%2==0){
            i++;
            }
}

}

void affiche(int *tab, int taille) {
    paire_impaire(tab, taille);  

    printf("tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);  
    }
    printf("\n");
}

int main() {
    
    int tab[] = {4, 3, 1, 6, 5, 8, 9, 1, 7, 8};
    int taille = 10;  
    affiche(tab, taille); 
    return 0; 
}