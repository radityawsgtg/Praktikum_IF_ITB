#include <stdio.h>
#include <math.h>
#include "sdf.h"

Point MakePoint(float x, float y){
    Point P;
    Y(P) = y;
    X(P)= x;
    return P;
}


Vector MakeVector(float dx, float dy){
    Vector V;
    DX(V)= dx;
    DY(V) = dy;
    return V;
}


/* ***************************************************************** */
/* OPERASI MATEMATIKA & VEKTOR                                       */
/* ***************************************************************** */
float Jarak(Point p1, Point p2){
    float selisih_x = X(p2) - X(p1);
    float selisih_y = Y(p2) - Y(p1);
    return sqrt ((selisih_x * selisih_x)+ (selisih_y * selisih_y));
}
/*  I.S. p1 dan p2 terdefinisi
    F.S. Menghasilkan jarak Euclidean antara p1 dan p2 
    Rumus jarak Euclidean: sqrt((x2-x1)^2 + (y2-y1)^2) */


void Normalize(Vector *v){
    float len = sqrt((DX(*v) * DX(*v)) + (DY(*v) * DY(*v)));
    if (len != 0.0)
    {
        DX(*v) = DX(*v) / len;
        DY(*v) = DY(*v) / len;
    }
    
}
    
/*  I.S. v terdefinisi dan memiliki panjang tidak nol
    F.S. v menjadi vektor satuan (panjang = 1.0) jika panjang awalnya tidak nol 
    Rumus normalize: v = v / ||v|| 
    ||v|| = sqrt(dx^2 + dy^2) */

/* ***************************************************************** */
/* OPERASI DASAR                                                     */
/* ***************************************************************** */
float SDF_Circle(Point p, Point center, float radius){
    return Jarak(p,center) - radius;
}


/*  I.S. p, center, dan radius terdefinisi
    F.S. Menghasilkan nilai signed distance dari titik p ke lingkaran
         berpusat di center dengan jari-jari radius.
         Nilai negatif berarti titik berada di dalam lingkaran,
         nol berarti tepat di tepi, dan positif berarti di luar lingkaran. 
    SDF dihitung sebagai jarak dari titik p ke pusat lingkaran dikurangi jari-jari. */

Point Move(Point p, Vector v, float step){
    Point pt_n;
    X(pt_n) = X(p)+ (DX(v)*step);
    Y(pt_n)= Y(p) + (DY(v)*step);
    return pt_n;
}

/*  I.S. p, v, dan step terdefinisi
    F.S. Menghasilkan titik baru hasil perpindahan titik p sejauh step
         ke arah vektor v */