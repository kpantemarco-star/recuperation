
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

// question 1.1
typedef struct {
    float abscisse, ordonee;
}Point;

// question 1.2
typedef struct {
    Point A; 
    Point B;
} Droite;

// question 1.3
Droite lireDroite() {
    Droite d;
    printf("Entrez l'abscisse du premier point : ");
    scanf("%f", &d.A.abscisse);
    printf("Entrez l'ordonnée du premier point : ");
    scanf("%f", &d.A.ordonee);
    printf("Entrez l'abscisse du second point : ");
    scanf("%f", &d.B.abscisse);
    printf("Entrez l'ordonnée du second point : ");
    scanf("%f", &d.B.ordonee);
    
    return d;
}

// question 1.4
void AfficheDroite(Droite d) {
    printf("Coordonnées du premier point (%.2f ; %.2f)\n", d.A.abscisse, d.A.ordonee);
    printf("Coordonnées du second point (%.2f ; %.2f)\n", d.B.abscisse, d.B.ordonee);
}

// question 1.5
int Parallele(Droite d1, Droite d2) {
    
    float ABx = d1.B.abscisse - d1.A.abscisse;
    float ABy = d1.B.ordonee - d1.A.ordonee;
    
    
    float CDx = d2.B.abscisse - d2.A.abscisse;
    float CDy = d2.B.ordonee - d2.A.ordonee;
    
    float produit1 = ABx * CDy;
    float produit2 = ABy * CDx;
    
    if (produit1 == produit2) {
        return 1; 
    } else {
        return 0; 
    }
}

// question 2.1 
typedef struct {
    float a;
    float b;
} EqDroite;

// question 2.2
EqDroite CalculEquaDroite(Droite d) {
    EqDroite eq;
    
    eq.a = (d.B.ordonee - d.A.ordonee) / (d.B.abscisse - d.A.abscisse);
    
    eq.b = d.A.ordonee - eq.a * d.A.abscisse;
    
    return eq;
}


int main()
{
   Droite d1, d2;
   d1 = lireDroite();
   AfficheDroite(d1);
   d2 = lireDroite();
   AfficheDroite(d2);
   int parallele = Parallele(d1, d2);
   if (parallele == 1){
       printf("les deux Droite sont colinéaire\n");
   }else{
       printf("les deux Droite sont Parallele\n");
   }
   EqDroite eq1 = CalculEquaDroite(d1);
   printf("Équation de d1 : y = %.2fx + %.2f\n", eq1.a, eq1.b);
    return 0;
}