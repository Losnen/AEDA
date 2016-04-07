#pragma once
#include <iostream>
#include <cstdlib>

#include "dispersion.h"

using namespace std;

template <class T>
class Pseudo: public Dispersion<T>
{
    private:
        
        int tam;
    
    public:
        
        Pseudo(int n);
        ~Pseudo(void);
        virtual int h(T X); 
};

template <class T>
Pseudo<T>::Pseudo(int n):
tam(n)
{}

template <class T>
int Pseudo<T>::h(T x)
{
    srand(x);
    return (rand() % tam);
}