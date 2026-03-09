#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int nb0=0, j=0, nb=0, nb1, nb2, nb3, nb4, i;
    int tab_alea[4], tab_jeu[4];
    srand(time(NULL));

    tab_alea[0] = (rand() % 9) + 1;
    tab_alea[1] = (rand() % 9) + 1;
    tab_alea[2] = (rand() % 9) + 1;
    tab_alea[3] = (rand() % 9) + 1;

    printf("|");
    for (i = 0; i < 4; i++)
    {
        printf(" %d |", tab_alea[i]);
    }
    printf("\n");

    printf("entrez votre combinaison de code compris entre 1-9 dans lordre voulu: ");
    scanf("%d %d %d %d", &nb1, &nb2, &nb3, &nb4);

    while (nb1 < 1 || nb1 > 9 || nb2 < 1 || nb2 > 9 || nb3 < 1 || nb3 > 9 || nb4 < 1 || nb4 > 9)
    {
        printf("entrez votre combinaison de code compris entre 1-9 dans lordre voulu: ");
        scanf("%d %d %d %d", &nb1, &nb2, &nb3, &nb4);
    }

    printf("\n");

    tab_jeu[0] = nb1;
    tab_jeu[1] = nb2;
    tab_jeu[2] = nb3;
    tab_jeu[3] = nb4;

    for (i = 0; i < 4; i++)
    {
        if (tab_alea[i] == tab_jeu[i])
        {
            nb0++;
        }
  
    }
      printf("Chiffre bien placer: %d \n", nb0);

    /*printf("|");
    for (i = 0; i < 4; i++)
    {
        printf(" %d |", tab_jeu[i]);
    }*/

    printf("\n");

    printf("la combinaison masquer est:  |");
    for (i = 0; i < 4; i++)
    {
        printf(" %d |", tab_alea[i]);
    }
     
   for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (tab_alea[i] == tab_jeu[j]) {
                nb++;
            }
        }
    }
    printf("\n");
    printf("il y a %d nombre mal placer ", nb);
}