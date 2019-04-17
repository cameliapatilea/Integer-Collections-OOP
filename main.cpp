#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include "lista_numere.h"
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int inmultire_matrice_vector(Matrice_Patratica A, Vector X, Vector Y)
{
    int ok = 1;
    int i = 0;
    for (i = 0; i < A.get_linii() && ok == 1; i++)
    {
        Vector V;
        V = A.get_linie(i) * X;
        if(V.suma_elemente() != Y[i])
            ok = 0;
    }
    return ok;
}


int main() {

    Vector X, Y, Z;
    Matrice_Patratica Mp1, Mp2, A;
    Matrice_Oarecare Mo1, Mo2, B;

    /*cin>>Mp1>>Mp2;
    cout<<Mp1.get_determinant()<<'\n';
    cout<<Mp1 + Mp2;*/

    /*cin>>Mo1>>Mo2;
    cout<<Mo1 + Mo2;*/

    /*cin>>X;
    cin>>Y;
    cin>>Z;

    vector<Vector> de_sortat;
    de_sortat.push_back(X);
    de_sortat.push_back(Y);
    de_sortat.push_back(Z);

    sort(de_sortat.begin(), de_sortat.end());

    for (int i = 0; i < 3; i++) {
        cout<<de_sortat[i];
    }*/

    /*cin>>A;
    cout<<inmultire_matrice_vector(A, X, Y)<<'\n';

    X.sortare();
    cout<<X;*/


}