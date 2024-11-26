#include <stdio.h>

void trie(int *tab, int taille) {
    int min, i, j, position, tmp, debut, fin;
printf("choisissez debut et fin : ");
    scanf( "%d %d", &debut, &fin );
    for (i = debut; i < fin; i++) {
        min = tab[i];  
        position = i;  

        for (j = i + 1; j < taille; j++) {
            if (tab[j] < min) {
                min = tab[j];
                position = j; 
            }
        }
        tmp = tab[position];
        tab[position] = tab[i];
        tab[i] = tmp;
    }
}

void affiche(int *tab, int taille) {
    trie(tab, taille);  

    printf("tableau trié : ");
    for (int i = 0; i < taille; i++) {
        printf("%d, ", tab[i]);  
    }
    printf("\n");
}



int main() {
    
    int tab[] = {2, 8, 7, -5, -4, 3, 42, 16, -15, 4};
    int taille = 10;  
    affiche(tab, taille); 
    return 0; 
}
