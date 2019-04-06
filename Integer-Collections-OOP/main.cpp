#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include "lista_numere.h"
using namespace std;

ifstream f("date.in");
ofstream g("date.out");

int main()
{
    /*
     //citire, memorare si afisare a n obiecte de tip Vector
     int n;
    cin >> n;
    Vector *vector_obiecte = new Vector[n + 1];
    for(int i = 1; i <= n; i++)
    {
        cin >> vector_obiecte[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cout << vector_obiecte[i] << '\n';
    }*/
     Vector V, V2, V3;
     cin >> V;
     cin >> V2;
   int suma = V.suma_elemente(V);
   cout <<"Suma elementelor vectorului este " <<  suma << '\n';
   int *maxim = V.maxi(V);
   cout <<"Elementul maxim este " <<  maxim[1] << " si se afla pe pozitia  " << maxim[2] << endl;
    V.sortare();
    cout << V;
    cout << '\n';
    cout << "inmultirea a doi vectori" << '\n';
      V3 = V * V2;
    cout << V3;
}