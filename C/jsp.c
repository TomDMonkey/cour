#include <stdio.h>
#include <unistd.h>

int tube[2];
int pipe(int tube[2]);


int main()
{



    FILE *fichier;
    fichier=fopen("titi.txt", "w");
    fprintf(fichier, "ca marche crari\n");
    fclose(fichier);

}