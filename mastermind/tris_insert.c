#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void tris_insert_for(int *tab, int taille){
    int i, j, temps;
    for ( i = 1; i < taille; i++)
    {
        for(j=i; j>=0; j--){
            if (temps<tab[j-1])
            {
                tab[j] = tab[j-1];
                tab[j-1] = temps;
            }
            
        }
    }
    
}

void tris_bull(int *tab, int taille){
    int i,j,temps;
    for (  i=0 ; i < taille; i++)
    {
        for ( j = 0; j < taille-i; j++)
        {
            if ()
            {
                /* code */
            }
            
        }
        
    }
    
}