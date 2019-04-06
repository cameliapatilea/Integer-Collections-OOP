#ifndef LISTA_NUMERE_H
#define LISTA_NUMERE_H
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include "lista_numere.h"
using namespace std;

class Vector{
protected:
    int dim;
    int *v;
public:
    Vector()
    {
        dim = 1;
        v = nullptr;
    }
    Vector(int dim)
    {
        this->dim = dim;
        this->v = new int[dim];
    }
    virtual ~Vector()
    {
       if(v != nullptr)
       {
           delete[] v;
           v = nullptr;
       }
    }
    int get_dimensiune()
    {
        return dim;
    }
    friend istream &operator>>(istream &input, Vector &vector)
    {
        input >> vector.dim;
        delete[] vector.v;
       vector.v = new int[vector.dim + 1];
        for(int i = 1; i <= vector.dim; i++)
           input >> vector.v[i];
        return input;
    }
    friend ostream &operator<<(ostream &output,const Vector &vector)
    {
        output << vector.dim << '\n';
        for(int i = 1; i <= vector.dim; i++)
            output << vector.v[i] << " ";
        return output;
    }
     Vector operator*(const Vector &V2)
    {
        Vector V3(this->dim);
        for(int i = 1; i <= V3.dim; i++)
            V3.v[i] = this->v[i] * V2.v[i];
        return V3;

    }
    Vector (const Vector &V)
    {
        dim = V.dim;
        v = new int [V.dim + 1];
        for(int i = 1; i <= V.dim ; i++)
            v[i] = V.v[i];
    }
   Vector &operator=(const Vector &v_copiat)
    {
        if(this == &v_copiat) return *this;
        delete[] v;
        dim = v_copiat.dim;
        v = new int[dim + 1];
        for(int i = 1; i <= dim; i++)
            v[i] = v_copiat.v[i];
        return *this;
    }
    Vector &operator[](int pozitie)
    {
        if(pozitie <= dim && pozitie > 0)
            return v[pozitie];
    }
    int suma_elemente(Vector v)
    {
        int suma = 0;
        for(int i = 1; i <= v.dim ; i++)
            suma = suma + v.v[i];
        return suma;
    }
    int* maxi(Vector V)
    {
        int *vector_maxi = new int[3];

            vector_maxi[1] = -999999999;
        for(int i = 1; i <= V.dim; i++)
            if(V.v[i] > vector_maxi[1])
            {
                vector_maxi[1] = V.v[i];
                vector_maxi[2] = i;
            }
         return vector_maxi;
    }
    void sortare()
    {
        for(int i = 1; i < dim; i++)
            for(int j = i + 1; j <= dim; j++)
                if(v[i] > v[j])
                {
                    int aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
    }

};
/*class Matrice{
protected:
    Vector *m;
public:
    Matrice()
    {
        m = NULL;
    }
    Matrice(Vector *m)
    {
       for(int i = 0; i < dim; i++)

    }
    ~Matrice()
    {
        for(int  i = 1; i <= dim; i++)
            delete[] m[i];
        delete[] m;
    }

};
class Matrice_oarecare: public Matrice{
protected:
    int lin;
public:

};
class Matrice_patratica: public Matrice{
    int dim;
public:
    Matrice_patratica()

};
*/
#endif