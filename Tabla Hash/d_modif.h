#pragma once
#include <iostream>
#include <cstdlib>

#include "dispersion.h"

using namespace std;

template <class T>
class Dmodificacion: public Dispersion<T>
{
    public:
        
        Dmodificacion(void);
        ~Dmodificacion(void);
        virtual int h(T X); 
};

template <class T>
Dmodificacion<T>::Dmodificacion(void)
{}

template <class T>
int Dmodificacion<T>::h(T x)
{
    return 0;
}