#pragma once
#include <iostream>
#include <cstdlib>

#include "dispersion.h"

using namespace std;

template <class T>
class Modulo: public Dispersion<T>
{
    private:
        
        int tam;
    
    public:
        
        Modulo(int n);
        ~Modulo(void);
        virtual int h(T X); 
};

template <class T>
Modulo<T>::Modulo(int n):
tam(n)
{}

template <class T>
int Modulo<T>::h(T x)
{
    int r = (x % tam);
    return r;
}