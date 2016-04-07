#pragma once
#include <iostream>
#include "exploracion.h"
#include "d_pseudo.h"
#include "d_modulo.h"

using namespace std;

template <class T>
class Cuadratica: public Exploracion<T>
{
    private:
      int tam;
      Dispersion<T>*  disp;
      
    public:
      
      Cuadratica(int n, Dispersion<T>* A);
      virtual int g(T X, int intento); 
};

template <class T>
Cuadratica<T>::Cuadratica(int n, Dispersion<T>* A):
tam(n),
disp(A)
{}

template <class T>
int Cuadratica<T>::g(T X, int intento) 
{
    int aux = disp->h(X);
    return ((aux + (intento * intento)) % tam);
}