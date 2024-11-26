// transposé une matrice 

#include <stdio.h>

void affiche(int matrice[4][4], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d\t", matrice[i][j]);
        }
        printf("\n");
    }
}

void transpos(int matrice[4][4], int transpose[4][4], int n, int m) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            transpose[j][i] = matrice[i][j];
        }
    }
}

int main() {
    int matrice[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int transpose[4][4];
    int n = 4, m = 4;

    printf("matrice: \n");
    affiche(matrice, n, m);

    transpos(matrice, transpose, n, m);

    printf("transposition :\n");
    affiche(transpose, n, m);

}
