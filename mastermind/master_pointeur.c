#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int nb0=0, j=0, nb=0; 
    int nb1, nb2, nb3, nb4, i;
    int tab_alea[4], tab_jeu[4];

    int *p_alea;
    int *p_jeu;
    srand(time(NULL));

    p_alea = &tab_alea[0];
    *p_alea = (rand()%9)+1;
    p_alea++;
    *p_alea = (rand()%9)+1;
    p_alea++;
    *p_alea = (rand()%9)+1;
    p_alea++;
    *p_alea = (rand()%9)+1;
    p_alea++;

    printf("|");
    p_alea = &tab_alea[0];

    printf(" %d |", *p_alea);
    p_alea++;
    printf(" %d |", *p_alea);
    p_alea++;
    printf(" %d |", *p_alea);
    p_alea++;
    printf(" %d |", *p_alea);
    printf("\n");

    printf("entrez votre combinaison de code compris entre 1-9 dans lordre voulu: ");
    scanf("%d %d %d %d", &nb1, &nb2, &nb3, &nb4);

    while (nb1 < 1 || nb1 > 9 || nb2 < 1 || nb2 > 9 || nb3 < 1 || nb3 > 9 || nb4 < 1 || nb4 > 9)
    {
        printf("entrez votre combinaison de code compris entre 1-9 dans lordre voulu: ");
        scanf("%d %d %d %d", &nb1, &nb2, &nb3, &nb4);
    }

    printf("\n");

    p_alea = &tab_alea[0];
    *p_alea = nb1;
    p_alea++;
    *p_alea = nb2;
    p_alea++;
    *p_alea = nb3;
    p_alea++;
    *p_alea = nb4;
    p_alea++;

    for (i = 0; i < 4; i++)
    {
        if (*p_alea == *p_jeu)
        {
            nb0++;
        }
        p_alea++; p_jeu++;
    }
      printf("Chiffre bien placer: %d \n", nb0);

    /*printf("|");
    for (i = 0; i < 4; i++)
    {
        printf(" %d |", tab_jeu[i]);
    }*/

    /*printf("\n");

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
    printf("il y a %d nombre mal placer ", nb);*/
}
