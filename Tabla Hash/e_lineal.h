#pragma once
#include <iostream>
#include "d_pseudo.h"
#include "d_modulo.h"

using namespace std;

template <class T>
class Lineal: public Exploracion<T> 
{
    private:
      int tam;
      Dispersion<T>*  disp;
      
    public:
      
      Lineal(int n, Dispersion<T>* A);
      virtual int g(T X, int intento); 
};

template <class T>
Lineal<T>::Lineal(int n, Dispersion<T>* A):
tam(n),
disp(A)
{}

template <class T>
int Lineal<T>::g(T X, int intento) 
{
    int aux = disp->h(X);
    return ((aux + intento) % tam);
}