#include <stdio.h>

int comment(int *tab, int taille, int *d, int *f){
int max,i,j,maxsomme=1<<31;

    for(i=0; i<taille; i++){

        max=0;
        for(j=i;j<taille;j++){
            max = tab[j];
            if(max> maxsomme){
                maxsomme=max;
                *d= i;
                *f= j;
            }
        }
    }
    return maxsomme;
}

int main(){
    int t[]={8,7,-5,-4,-42,16,-15,4}, debut, fin;
    printf("%d\n", comment(t,8, &debut, &fin));
    printf("\n%d %d", debut, fin);
    return 0;
}