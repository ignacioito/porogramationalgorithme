// *****************************************************************************
//
//
//
//
// *****************************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define BUFF 20
#define TAILLE 4

void genererGrille()
{
	char grille[4][4];
	int indexL;
	int indexC;
	

	for(indexL = 0; indexL < TAILLE; indexL++)
	{
		for(indexC = 0; indexC < TAILLE; indexC++)
		{
			grille[indexL][indexC] = rand() % ('Z' - 'A' + 1) + 'A';
		}
	}

	for(indexL = 0; indexL < TAILLE; indexL++)
	{
		for(indexC = 0; indexC < TAILLE; indexC++)
		{
			printf(" %c ",grille[indexL][indexC]);
		}
		printf("\n");
	}
	
}

int lireFichier(char *filename, char motForme[])
{
	int a = 0;
	int b = 0;
    FILE *file = fopen(filename, "r");
    int nblines = 0;
  
    if (file == NULL )
      {
	perror("fopen");
	exit(1);
      }

    char mot[BUFF];
    while (fgets(mot, BUFF, file) != NULL) 
    {
	int l = strlen(mot);
	mot[l - 1] = '\0';
	
	a = strlen(mot);
	if(a >= b)
	{
		b = a;
	}

	if(!strcmp(mot, motForme)) return 1;
	}
    printf(" *** %d ****",b);
    fclose(file);
     return nblines;
}

int main()
{
	srand(time(NULL));
	char motForme[18];
	genererGrille();
	gets(motForme);
	if(lireFichier("francais.txt",motForme) == 1) printf(" Encontrou!\n");
	else printf(" NAO Encontrou!\n");
}