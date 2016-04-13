#pragma once
#include <iostream>
#include "d_pseudo.h"
#include "d_modulo.h"

using namespace std;

template <class T>
class Emodificacion: public Exploracion<T> 
{
    private:
      int tam;
      Dispersion<T>*  disp;
      
    public:
      
      Emodificacion(int n, Dispersion<T>* A);
      virtual int g(T X, int intento); 
};

template <class T>
Emodificacion<T>::Emodificacion(int n, Dispersion<T>* A):
tam(n),
disp(A)
{}

template <class T>
int Emodificacion<T>::g(T X, int intento) 
{
    int aux = disp->h(X);
    return ((tam - intento));
}