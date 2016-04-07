#pragma once
#include <iostream>
#include "d_pseudo.h"
#include "d_modulo.h"

using namespace std;

template <class T>
class Redisp: public Exploracion<T> 
{
    private:
      int tam;
      Dispersion<T>*  disp;
      
    public:
      
      Redisp(int n, Dispersion<T>* A);
      virtual int g(T X, int intento); 
};

template <class T>
Redisp<T>::Redisp(int n, Dispersion<T>* A):
tam(n),
disp(A)
{}

template <class T>
int Redisp<T>::g(T X, int intento) 
{
    int aux = disp->h(X);
    srand(X);
    int op = (rand() % 3);
    switch(op)
    {
        case 0:
            return((aux + intento) % tam);
        break;
        case 1:
            return(aux + (intento * intento) % tam);
        break;
        case 2:
            return((aux + intento * aux) % tam);
        break;
        default:
            cout << "Error en la generación del numero aleatorio" << endl;
            exit(0);
        break;
    }
}