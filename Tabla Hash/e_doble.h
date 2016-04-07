#pragma once
#include <iostream>
#include "d_pseudo.h"
#include "d_modulo.h"

using namespace std;

template <class T>
class Doble: public Exploracion<T> 
{
    private:
      int tam;
      Dispersion<T>*  disp;
      
    public:
      
      Doble(int n, Dispersion<T>* A);
      virtual int g(T X, int intento); 
};

template <class T>
Doble<T>::Doble(int n, Dispersion<T>* A):
tam(n),
disp(A)
{}

template <class T>
int Doble<T>::g(T X, int intento) 
{
    int aux = disp->h(X);
    return ((aux + (intento * aux)) % tam);
}