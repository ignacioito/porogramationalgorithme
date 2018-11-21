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

void genererGrille()
{
	char grille[4][4];
	int indexL;
	int indexC;
	int taille = 4;

	for(indexL = 0; indexL < taille; indexL++)
	{
		for(indexC = 0; indexC < taille; indexC++)
		{
			grille[indexL][indexC] = rand() % ('Z' - 'A' + 1) + 'A';
		}
	}

	for(indexL = 0; indexL < taille; indexL++)
	{
		for(indexC = 0; indexC < taille; indexC++)
		{
			printf(" %c ",grille[indexL][indexC]);
		}
		printf("\n");
	}
}

int lireFichier(char *filename)
{
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
	printf("%s, ", mot);
    }
    
    fclose(file);
    return nblines;
}

int main()
{
	srand(time(NULL));
	


	lireFichier("francais.txt");




}