#pragma once
#include <iostream>
#include <vector>
#include "celda.h"
#include <iomainp>
#include <cstdlib>

using namespace std;

template <class T>
class TablaHash
{
    private:
        
        vector<Celda<T> >   celdas;                                         //Vector de celdas
        int                 tam;                                            //Tamaño de la tabla
        int                 dispersion;                                     //Tipo de dispersión
        int                 exploracion;                                    //Tipo de exploración
        
        
    public:
    
        TablaHash(int tamc, int tamb, int ex, int disp);                    //Constructor    
        ~TablaHash(void);
        
        int dispersion_generica(T x);                                       //Función de dispersión genérica
        int dispersion_modulo(T x);                                         //Función de dispersión módulo
        int dispersion_aleatoria(T x);	                                    //Función de dispersión aleatoria      
        
        int exploracion_generica(T x,int intento);                          //Función de exploración genérica
        int exploracion_lineal(Clave x, int intento);		                //Función de exploración lineal
        int exploracion_cuadratica(Clave x, int intento);		            //Función de exploración cuadrática
        int exploracion_doble(Clave x, int intento);		                //Función de exploración dispersión doble
        int exploracion_redispersion(Clave x, int intento);	                //Función de exploración re-dispersión

};

template <class T>
TablaHash(int tamc, int tamb, int ex, int disp):
tam(tamc),
exploracion(ex),
dispersion(disp)
{
    celdas.resize(tam);
    for(int i =0;i<tam;i++)
    {
        celdas[i](tamb);
    }
}

template <class T>
~TablaHash(void)
{}

template <class T>
int dispersion_generica(T x)
{
    switch(dispersion)
    {
        case 0:
            return(dispersion_modulo(x));
        break;
        case 1:
            return(dispersion_aleatoria(x));
        break;
        default:
            cout << "Dispersión inválida" << endl;
            exit(1);
        break;
    }
}

template <class T>
int dispersion_modulo(T x)
{
    int r = (x % tam);
    return r;
}

template <class T>
int dispersion_aleatoria(T x)
{
    srand(x);
    return (rand() % tam);
}

template <class T>
int exploracion_generica(T x, int intento)
{
    switch(exploracion)
    {
        case 0:
            return(exploracion_lineal(x,intento));
        break;
        case 1:
            return(exploracion_cuadratica(x,intento));
        break;
        case 2:
            return(exploracion_doble(x,intento));
        break;
        case 3:
            return(exploracion_redispersion(x,intento));
        break;
        default:
            cout << "Exploración inválida" << endl;
            exit(1);
        break;
    }
}

template <class T>
int exploracion_lineal(Clave x, int intento)
{
    return((dispersion(x) + intento) % tam);
}

template <class T>
int exploracion_cuadratica(Clave x, int intento)
{
    return((dispersion(x) + (intento*intento)) % tam);	
}

template <class T>
int exploracion_doble(Clave x, int intento)
{
    return((dispersion(x) + (intento * dispersion_aleatoria(x))) % tam); 
}

template <class T>
int exploracion_redispersion(Clave x, int intento)
{
    
}