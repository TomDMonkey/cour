// dichotomi mais recursife, ca trouve la valeur la plus grande d'un tableau non trié

#include <stdlib.h>
#include <stdio.h>


// int maxi(int *tab, int taille){
//         int m=(d+f)/2;
//         if(tab[m] == e)
//                 return m;
//         if(d ==f)
//                 return -1;
//         if(tab[m]>= e)
//                 return maxi(tab, d, m-1, e);
//         else
//                 return maxi(tab, d, m+1, e);
// }

int maxi(int *t, int taille){
    int tmp;
    if(taille == 1){
        return t[0];
    }
    tmp = maxi(t+1, taille -1);
    return(tmp > t[0])?tmp:t[0];

}


int main(){
    int tableau[] = {1,2,5,6,8,9,75,15,32, 56};
    int taille = 10;
    printf("Position dans tableau : %d\n",  maxi(tableau, 10));

    }