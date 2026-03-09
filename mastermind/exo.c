#include <stdio.h>
#include <math.h>

typedef struct
{
    float abscisse, ordonee;
}point;

point lecture(){
    point p;
    printf("Entrez la valeur de l'abcisse : ");
    scanf("%f", &p.abscisse);
    printf("Entrez la valeur de l'ordonnée : ");
    scanf("%f", &p.ordonee);
    return p;
}

void affiche(point d){
    printf("Point(%.2f,%.2f)\n", d.abscisse, d.ordonee);
}

float distance_ecludien(point p1, point p2){
  return sqrt(pow(p2.abscisse - p1.abscisse,2) + pow(p2.ordonee-p1.ordonee,2));
}


int saisie_polygone(point pol[]){
    int nbpoint=0,i;
    for ( i = 0; i < nbpoint; i++)
    {
        pol[i]=lecture();
    }
    return nbpoint;
}

float perimetre(point poly, int nbpint){

}


int main(){
    point p1, p2;
    p1=lecture();
    // p2=lecture();
    affiche(p1);
    // affiche(p2);
    point polygone[30];
}    


typedef struct {
    float abscisse, ordonee;
}Point;

typedef struct {
    Point A; 
    Point B;
} Droite