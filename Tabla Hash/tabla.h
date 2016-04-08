#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>

#include "d_modulo.h"
#include "d_pseudo.h"
#include "e_cuadratica.h"
#include "e_doble.h"
#include "e_lineal.h"
#include "e_redisp.h"
#include "celda.h"

using namespace std;

template <class T>
class TablaHash
{
    private:
        
        vector<Celda<T> >       celdas;                                         //Vector de celdas
        int                     tam;                                            //Tamaño de la tabla
        Dispersion<T>*          dispersion;                                     //Tipo de dispersión
        Exploracion<T>*         exploracion;                                    //Tipo de exploración
        
        
    public:
    
        TablaHash(int tamc, int tamb, Exploracion<T>* ex, Dispersion<T>* disp);  //Constructor    
        ~TablaHash(void);
        
        int dispersion_generica(T x);                                           //Función de dispersión genérica
        int exploracion_generica(T x,int intento);                              //Función de exploración genérica
        
        Celda<T>& operator[](int i);                                            //Operador que accede a los elementos de la tabla
        

};

template <class T>
TablaHash<T>::TablaHash(int tamc, int tamb, Exploracion<T>* ex, Dispersion<T>* disp):
tam(tamc),
exploracion(ex),
dispersion(disp)
{
    celdas.resize(tam);
    for(int i = 0; i < tam; i++)
    {
        celdas[i].resize(tamb);
    }
}

template <class T>
TablaHash<T>::~TablaHash(void)
{}

template <class T>
int TablaHash<T>::dispersion_generica(T x)
{
    return (dispersion->h(x));
}

template <class T>
int TablaHash<T>::exploracion_generica(T x, int intento)
{
    return (exploracion->g(x,intento));
}

template <class T>
Celda<T>& TablaHash<T>::operator[](int i)
{
    return celdas[i];
}