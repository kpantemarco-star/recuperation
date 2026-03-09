#include<stdio.h>
#include<time.h>
#include <stdlib.h>

void tri_select(int tab[], int taille,int* tab_trie){
    int i,j,k;
    int min = tab[0];
    for(i=0;i<taille;i++){
        for(j=0;j<taille;j++){
            if(tab[j]<min && tab[j]>0){
                min = tab[j];
                k=j;
            }
        }
        tab[k] = -1;
        tab_trie[i] = min;
        min=10000;
    }
}

int main() {
    int tab[100];
    int* tab_trie;
    tab_trie = (int*)malloc(100 * sizeof(int));
    int i;
    srand(time(0));
    printf("\n\n");
    for(i=0;i<100;i++){
        tab[i]=rand()%1000+1;
        printf("%d ",tab[i]);
    }
    printf("\n\n\n");
    tri_select(tab,100,tab_trie);
    printf("\n\n\n");
    for(i=0;i<100;i++){
        printf("%d ",tab_trie[i]);
    }
    return 0;
}