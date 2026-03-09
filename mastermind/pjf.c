#include <stdio.h>
#include <math.h>

typedef struct
{
    float abscisse, ordonee;
}Point;

typedef struct 
{
   Point p1; 
   Point p2;
}Droite;

Point lecture(){
    Point p;
    printf("Entrez la valeur de l'abcisse : ");
    scanf("%f", &p.abscisse);
    printf("Entrez la valeur de l'ordonnée : ");
    scanf("%f", &p.ordonee);
    return p;
}
Droite liredroite(){
    Droite d;
    printf("coordonnees du premier point\n");
    d.p1 = lecture();
    printf("Coordonnees du second point\n");
    d.p2 = lecture();
    return d;
}

void AfficheDroite(Droite d){
    printf("Coordonnées du premier point (%.2f ; %.2f)\n", d.p1.abscisse, d.p1.ordonee);
    printf("Coordonnées du premier second (%.2f ; %.2f)\n", d.p2.abscisse, d.p2.ordonee);
}

int Parallele(Droite d1, Droite d2){
    
    float ABx = d1.p2.abscisse - d1.p1.abscisse;
    float ABy = d1.p2.ordonee - d1.p1.ordonee;
    
    
    float CDx = d2.p2.abscisse - d2.p1.abscisse;
    float CDy = d2.p2.ordonee - d2.p1.ordonee;
    
    float produit1 = ABx * CDy;
    float produit2 = ABy * CDx;

    if (produit1 == produit2) {
        return 1; 
    } else {
        return 0; 
    }
}

// -----------------------------------------------------------------

// question 2.1 
typedef struct {
    float a;
    float b;
} EqDroite;

// question 2.2
EqDroite CalculEquaDroite(Droite d) {
    EqDroite eq;
    
    eq.a = (d.p2.ordonee - d.p1.ordonee) / (d.p2.abscisse - d.p1.abscisse);
    
    eq.b = d.p1.ordonee - eq.a * d.p1.abscisse;
    
    return eq;
}

// ------------------------------------------------------------------

// question 3.1

int Egal(Droite d1, Droite d2) {
    EqDroite eq1 = CalculEquaDroite(d1);
    EqDroite eq2 = CalculEquaDroite(d2);

    if ((eq1.a == eq2.a) && (eq1.b == eq2.b)) {
        return 1; 
    } else {
        return 0; 
    }
}

// question 3.2 

int Parallele2(Droite D1, Droite D2) {
    EqDroite eq1 = CalculEquaDroite(D1);
    EqDroite eq2 = CalculEquaDroite(D2);

    if (eq1.a == eq2.a) {
        return 1; 
    } else {
        return 0; 
    }
}

// question 3.3
int Secante(Droite D1, Droite D2) {
    EqDroite eq1 = CalculEquaDroite(D1);
    EqDroite eq2 = CalculEquaDroite(D2);

    if (eq1.a != eq2.a) {
        return 1; 
    } else {
        return 0; 
    }
}

// question 3.4
int Perpendiculaire Droite D1, Droite D2 {
    EqDroite eq1 = CalculEquaDroite(D1);
    EqDroite eq2 = CalculEquaDroite(D2);

    if (eq1.a * eq2.a < 0) {
        return 1; 
    } else {
        return 0; 
    }
}

// question 3.5
Point Intersection(Droite D1, Droite D2) {
    EqDroite eq1 = CalculEquaDroite(D1);
    EqDroite eq2 = CalculEquaDroite(D2);
    Point p;

    p.abscisse = (eq2.b - eq1.b) / (eq1.a - eq2.a);
    p.ordonee = eq1.a * p.abscisse + eq1.b;

    return p;
}

// question 3.6

int PointInterSectionDansSegment (Droite D1, Droite D2, Point pt_intersec){

}

// teste des fonction 
void TesterDroites(Droite d1, Droite d2) {
    // Vérifier si les droites sont parallèles
    if (Parallele2(d1, d2)) {
        printf("Les droites sont parallèles.\n");
    } else {
        printf("Les droites ne sont pas parallèles.\n");
    }

    // Vérifier si les droites sont sécantes
    if (Secante(d1, d2)) {
        printf("Les droites sont sécantes.\n");

        // Calculer le point d'intersection
        Point intersection = Intersection(d1, d2);
        printf("Point d'intersection : (%.2f, %.2f)\n", intersection.abscisse, intersection.ordonee);
    } else {
        printf("Les droites ne sont pas sécantes.\n");
    }

    // Vérifier si les droites sont perpendiculaires
    if (Perpendiculaire(d1, d2)) {
        printf("Les droites sont perpendiculaires.\n");
    } else {
        printf("Les droites ne sont pas perpendiculaires.\n");
    }
}


int main(){

    Droite d1, d2; 
    d1 = liredroite();
    AfficheDroite(d1);
    d2 = liredroite();
    AfficheDroite(d2);

   EqDroite eq1 = CalculEquaDroite(d1);
   printf("Équation de d1 : y = %.2fx + %.2f\n", eq1.a, eq1.b);
   Egal(d1,d2);
    int egal = Egal(d1, d2);
    if (egal == 1){
        printf("les droite sont égales\n");
    }else{
        printf("les droite ne sont pas égales\n");
    }

    // Cas 1
    Droite d1 = {{0, 0}, {4, 4}}; // A(0,0), B(4,4)
    Droite d2 = {{0, 4}, {4, 0}}; // C(0,4), D(4,0)

    printf("Cas 1 :\n");
    TesterDroites(d1, d2);

    // Cas 2
    d1 = (Droite){{0, 0}, {2, 2}}; // A(0,0), B(2,2)
    d2 = (Droite){{3, 0}, {5, 2}}; // C(3,0), D(5,2)

    printf("\nCas 2 :\n");
    TesterDroites(d1, d2);

    // Cas 3
    d1 = (Droite){{0, 0}, {2, 2}}; // A(0,0), B(2,2)
    d2 = (Droite){{0, 1}, {2, 3}}; // C(0,1), D(2,3)

    printf("\nCas 3 :\n");
    TesterDroites(d1, d2);

    // Cas 4
    d1 = (Droite){{0, 0}, {2, 4}}; // A(0,0), B(2,4)
    d2 = (Droite){{0, 0}, {4, -2}}; // C(0,0), D(4,-2)

    printf("\nCas 4 :\n");
    TesterDroites(d1, d2);
}

