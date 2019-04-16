#ifndef LISTA_NUMERE_H
#define LISTA_NUMERE_H

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include "lista_numere.h"

using namespace std;

class Vector {

    /*
     * Zona de date este protected, chiar daca nu se fac mosteniri.
     */
protected:
    int dim;
    int *v;

public:

    /*
     * Constructori + Destructor
     */

/*    Vector() {
        dim = 0;
        v = new int[0];
    }*/

    Vector(int dim = 0) {
        this->dim = dim;
        if (dim == 0)
            v = NULL;
        else {
            v = new int[dim];
        }
    }

    Vector(const Vector &V) {
        if (V.dim == 0 || V.v == NULL) {
            dim = 0;
            v = NULL;
        }
        else {
            dim = V.dim;

            //delete []v;

            v = new int[dim];
            for (int i = 0; i < dim; i++)
                v[i] = V.v[i];
        }
    }

    virtual ~Vector() {
        if (v != NULL)
            delete []v;
        this->dim = 0;
    }

    /*
     * Metode GET + SET
     */

    int get_dimensiune() {
        return dim;
    }

    /*
     * Operatori de citire + afisare
     */

    friend istream &operator>>(istream &input, Vector &vector) {
        if (vector.dim == 0)
            input >> vector.dim;

        vector.v = new int[vector.dim + 1];
        for (int i = 0; i < vector.dim; i++)
            input >> vector.v[i];
        return input;
    }

    friend ostream &operator<<(ostream &output, const Vector &vector) {
        // output << vector.dim << '\n';
        for (int i = 0; i < vector.dim; i++)
            output << vector.v[i] << " ";
        output << '\n';
        return output;
    }

    /*
     * Alti operatori
     */

    Vector operator*(const Vector &V2) {
        if (dim != V2.dim)
            throw invalid_argument("Error! Can't multiply different sizes vectors!");

        Vector V3(this->dim);
        for (int i = 0; i < V3.dim; i++)
            V3.v[i] = this->v[i] * V2.v[i];
        return V3;

    }

    Vector operator+(const Vector &V2) {

        if (dim != V2.dim)
            throw invalid_argument("Error! Can't add different sizes vectors!");

        Vector V3(this->dim);
        for (int i = 0; i < V3.dim; i++)
            V3.v[i] = this->v[i] + V2.v[i];
        return V3;
    }

    Vector &operator=(const Vector &v_copiat) {
        if (v == v_copiat.v) return *this;

        delete []v;

        dim = v_copiat.dim;
        v = new int[dim + 1];
        for (int i = 0; i < dim; i++)
            v[i] = v_copiat.v[i];
        return *this;
    }

    bool operator==(const Vector &V) {
        if (this == &V) return true;
        if (this->dim != V.dim) return false;
        for (int i = 0; i < this->dim; i++)
            if (this->v[i] != V.v[i])
                return false;
        return true;
    }

    bool operator!=(const Vector &V) {
        if (this == &V)
            return false;
        else return true;
    }

    bool operator<(const Vector &V) {
        if (this->dim < V.dim) return true;
        if (this->dim > V.dim) return false;
        for (int i = 0; i < this->dim; i++)
            if (this->v[i] >= V.v[i])
                return false;
        return true;
    }

    bool operator<=(const Vector &V) {
        if (this->dim < V.dim) return true;
        if (this->dim > V.dim) return false;
        for (int i = 0; i < this->dim; i++)
            if (this->v[i] > V.v[i])
                return false;
        return true;
    }

    bool operator>(const Vector &V) {
        if (this <= &V) return false;
        return true;
    }

    bool operator>=(const Vector &V) {
        if (this < &V) return false;
        return true;
    }

    int &operator[](int pozitie) {
        if (pozitie < dim && pozitie >= 0)
            return v[pozitie];
    }

    /*
     * Metode aditionale
     */

    int suma_elemente() {
        int suma = 0;
        for (int i = 0; i < this->dim; i++)
            suma = suma + this->v[i];
        return suma;
    }

    int *maxi() {
        int *vector_maxi = new int[3];

        vector_maxi[1] = -999999999;
        for (int i = 0; i < this->dim; i++)
            if (this->v[i] > vector_maxi[1]) {
                vector_maxi[1] = this->v[i];
                vector_maxi[2] = i;
            }
        return vector_maxi;
    }

    void sortare() {
        for (int i = 0; i < dim - 1; i++)
            for (int j = i + 1; j < dim; j++)
                if (v[i] > v[j]) {
                    int aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
    }

    /*
     * Prietenie intre clasele Vector si Matrice
     */

    friend class Matrice;

};

/* ----------------------------------------------------------------------------------- */

// Clasa abstracta Matrice

class Matrice {

    /*
     * Zona de date este protected pentru a putea efectua mostenirile ulterioare
     */
protected:
    Vector *m;
    int nr_coloane;
    int nr_linii;

public:

    /*
     * Constructori + Destructor
     */

    /*Matrice() {
        nr_coloane = 0;
        nr_linii = 0;
        m = NULL;
    }*/

    Matrice(int lin = 0, int col = 0) {
        nr_linii = lin;
        nr_coloane = col;

        if (lin == 0 || col == 0) {
            nr_linii = 0;
            nr_coloane = 0;
            m = NULL;
        }
        else {
            m = new Vector[lin];
            for (int indice = 0; indice < lin; indice++) {
                Vector v(col);
                m[indice] = v;
            }
        }
    }

    Matrice(int lin, int col, Vector *vector) {

        if (vector == NULL || lin == 0 || col == 0) {
            nr_linii = 0;
            nr_coloane = 0;
            m = NULL;
        }
        else {
            nr_linii = lin;
            nr_coloane = col;

            delete []m;

            m = new Vector(lin);

            for (int i = 0; i < lin; i++)
                m[i] = vector[i];
        }
    }

    Matrice(const Matrice &M) {
        if (M.m == NULL || M.nr_linii == 0 || M.nr_coloane == 0) {
            nr_linii = 0;
            nr_coloane = 0;
            m = NULL;
        }
        else {
            nr_linii = M.nr_linii;
            nr_coloane = M.nr_coloane;

            delete []m;

            m = new Vector[nr_linii];

            for (int i= 0; i < nr_linii; i++)
                m[i] = M.m[i];
        }
    }

    virtual ~Matrice() {
        delete[] m;
    }
    Matrice operator+(const Matrice &M) {
        if (nr_coloane != M.nr_coloane)
            throw invalid_argument("Error! Different sizes!");
        else {
            Matrice_Patratica rez(nr_coloane);

            for (int i = 0; i < nr_coloane; i++) {
                rez.m[i] = m[i] + M.m[i];
            }

            return rez;
        }
    }

    /*
     * Metode GET + SET
     */

    virtual int get_linii() = 0;

    virtual int get_coloane() = 0;

    virtual Vector get_linie(int i) = 0;

};

/* ----------------------------------------------------------------------------------- */

class Matrice_Patratica : public Matrice {

    /*
     * Campul de date declarat este privat, deoarece acesta nu va fi mostenit mai departe
     */
private:

    int dim;

    /*
     * Metoda de calcul a determinantului unei matrice patratice foloseste un calcul iterativ
     */
    int determinant() {
        int i, j, total = 1, determinant = 1, num1, num2;

        int index;
        Vector temp(dim);

        for (int i = 0; i < dim; i++) {
            index = i;

            while (index < dim && m[index][i] == 0) {
                index++;
            }

            if (index == dim) {
                continue;
            }

            if (index != i) {
                temp = m[index];
                m[index] = m[i];
                m[i] = temp;

                determinant = determinant * pow(-1, index - i);
            }

            for (int j = 0; j < dim; j++) {
                temp = m[i];
            }

            for (int j = i + 1; j < dim; j++) {
                num1 = temp[i];
                num2 = m[j][i];

                for (int k = 0; k < dim; k++) {
                    m[j][k] = (num1 * m[j][k]) - (num2 * temp[k]);
                }

                total = total * num1;
            }
        }

        for (int i = 0; i < dim; i++) {
            determinant = determinant * m[i][i];
        }

        return determinant / total;
    }


public:

    /*
     * Constructori + Destructor
     */

    /*Matrice_Patratica() : Matrice() {
        dim = 0;
    }*/

    Matrice_Patratica(int dim = 0) : Matrice(dim, dim) {
        this->dim = dim;
    }

    Matrice_Patratica(int dim, Vector *v) : Matrice(dim, dim, v) {
        this->dim = dim;
    }

    Matrice_Patratica(const Matrice_Patratica &M) {
        dim = M.dim;
        nr_coloane = dim;
        m = new Vector[dim + 1];
        for (int i = 0; i < M.dim; i++)
            m[i] = M.m[i];
    }

    ~Matrice_Patratica() {
        dim = 0;
    }

    /*
     * Metode GET + SET
     */

    int get_linii() {
        return dim;
    }

    int get_coloane() {
        return dim;
    }

    Vector get_linie(int i) {
        return this->m[i];
    }

    int get_dim() {
        return dim;
    }

    /*
     * Operatori de citire + afisare
     */

    friend istream &operator>>(istream &input, Matrice_Patratica &M) {
        input >> M.dim;
        M.nr_coloane = M.dim;

        //delete[] M.m;
        M.m = new Vector[M.dim + 1];
        for (int i = 0; i < M.dim; i++) {
            M.m[i] = Vector(M.dim);
            input >> M.m[i];
        }
        return input;
    }

    friend ostream &operator<<(ostream &output,Matrice_Patratica &M) {
        output << M.dim << '\n';
        for (int i = 0; i < M.dim; i++)
            output << M.m[i];
        output << "Determinant: " << M.determinant() << '\n';
        return output;
    }

    /*
     * Alti operatori
     */

    Matrice_Patratica &operator=(const Matrice_Patratica &M) {
        if (m == M.m)
            return *this;

        dim = M.dim;

        m = new Vector[M.dim];

        /*for (int i = 0; i < dim; i++) {
            m[i] = Vector(dim);
        }*/

        for (int i = 0; i < dim; i++)
            m[i] = M.m[i];
        return *this;
    }

    Vector &operator[](int pozitie) {
        if (pozitie < dim && pozitie >= 0)
            return m[pozitie];
    }

    /*
     * Metode aditionale
     */

    int get_determinant() {
        return determinant();
    }

    bool verifica_matrice_triunghiular_diagonala() {
        for (int i = 1; i < dim; i++)
            for (int j = 0; j < i; j++)
                if (this->m[i][j] != 0) {
                    return false;
                }

        for (int i = 0; i < dim; i++)
            for (int j = i; j < dim; j++)
                if (this->m[i][j] == 0) {
                    return false;
                }

        return true;
    }
    Matrice_Patratica operator+(const Matrice_Patratica &M) {
        if (nr_coloane != M.nr_coloane)
            throw invalid_argument("Error! Different sizes!");
        else {
            Matrice_Patratica rez(nr_coloane);

            for (int i = 0; i < nr_coloane; i++) {
                rez.m[i] = m[i] + M.m[i];
            }

            return rez;
        }
    }
};

class Matrice_Oarecare : public Matrice {
private:
    int lin;
public:
    Matrice_Oarecare() : Matrice() {
        lin = 0;
    }

    Matrice_Oarecare(int lin, int col) : Matrice(lin, col) {
        this->lin = lin;
    }

    Matrice_Oarecare(int lin, int col, Vector *v) : Matrice(lin, col, v) {
        this->lin = lin;
    }

    //constructor copiere
    Matrice_Oarecare(const Matrice_Oarecare &M) {
        lin = M.lin;
        nr_coloane = M.nr_coloane;
        m = new Vector[M.lin + 1];
        for (int i = 0; i < M.lin; i++)
            m[i] = M.m[i];
    }

    ~Matrice_Oarecare() {
    }

    friend istream &operator>>(istream &input, Matrice_Oarecare &M) {
        input >> M.lin >> M.nr_coloane;

        //delete[] M.m;
        M.m = new Vector[M.lin + 1];
        for (int i = 0; i < M.lin; i++) {
            M.m[i] = Vector(M.nr_coloane);
            input >> M.m[i];
        }
        return input;
    }

    friend ostream &operator<<(ostream &output, const Matrice_Oarecare &M) {
        output << M.lin << " " << M.nr_coloane << '\n';
        for (int i = 0; i < M.lin; i++)
            output << M.m[i];
        return output;
    }

    int get_linii() {
        return lin;
    }

    int get_coloane() {
        return nr_coloane;
    }

    Vector get_linie(int i) {
        return this->m[i];
    }

    Matrice_Oarecare &operator=(const Matrice_Oarecare &M) {
        if (m == M.m)
            return *this;

        lin = M.lin;
        nr_coloane = M.nr_coloane;
        /*if (m != nullptr)
            delete[] m;*/
        m = new Vector[M.lin + 1];
        for (int i = 0; i < M.lin; i++)
            m[i] = M.m[i];
        return *this;
    }

    Matrice_Oarecare operator+(const Matrice_Oarecare &M) {
        if (lin != M.lin || nr_coloane != M.nr_coloane)
            throw invalid_argument("Error! Different sizes!");
        else {
            Matrice_Oarecare rez(lin, nr_coloane);

            for (int i = 0; i < lin; i++) {
                rez.m[i] = m[i] + M.m[i];
            }

            return rez;
        }
    }
};

#endif
