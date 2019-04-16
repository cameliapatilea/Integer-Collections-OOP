#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include "lista_numere.h"
using namespace std;

ifstream f("date.in");
ofstream g("date.out");
/*int inmultire_matrice_vector(Matrice A, Vector X, Vector Y)
{
    int ok = 1;
    for(int i = 1; i <= A.get_linii() && ok == 1; i++)
    {
        Vector V ;
        V = A.get_linie(i) * X;
        if(V.suma_elemente() != Y[i])
            ok = 0;
    }
    return ok;
}*/


int main() {

    /*Vector *v;
    v = new Vector[3];
    for (int i = 0; i < 3; i++) {
        Vector vaux(3);
        cin>>vaux;
        v[i] = vaux;
    }

    Matrice_Patratica MP1(3, v);
    Matrice_Patratica MP2;
    Matrice_Oarecare MO1(3, 3, v);
    Matrice_Oarecare MO2;*/

    /*Vector v1;
    Vector v2;

    cin>>v1;
    cin>>v2;

    cout<<v1 + v2;
    cout<<v1 * v2;
    cout<<v1.suma_elemente();
}*/
    Matrice_Patratica  M, M2;
    cin >> M >> M2;
    M  = M + M2;
    cout << M;
}