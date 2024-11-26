// recherche une valeur en divisant le tableau par 2  et on repete 

#include <stdlib.h>
#include <stdio.h>

int recherche(int* tab, int taille, int e){
    int i;
    for(i=0;i<taille;i++){
        if(tab[i]==e){
            return i;
        }
    }
    return -1;
}

int recherche_dichotomique(int* tab, int taille, int e){
    int debut = 0;
    int fin = taille;
    int milieu;
    int position = -1;
    while(debut<=fin && position == -1){
        milieu = (debut+fin)/2;
        if(tab[milieu] == e){
            position = milieu;
        }
        else if(tab[milieu] < e){
            debut = milieu+1;
        }
        else{
            fin = milieu-1;
        }
    }
    return position;
}

int main(){
    int tableau[] = {1,2,5,6,8,9,12,15,32};
    printf("Position dans tableau : %d\n", recherche_dichotomique(tableau, 9, 9));
}