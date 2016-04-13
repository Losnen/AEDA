#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <fstream>

#include "d_modulo.h"
#include "d_pseudo.h"
#include "d_modif.h"
#include "e_cuadratica.h"
#include "e_doble.h"
#include "e_modif.h"
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
        int                     intento;
        
    public:
    
        TablaHash(int tamc, int tamb, Exploracion<T>* ex, Dispersion<T>* disp);  //Constructor    
        ~TablaHash(void);
        
        int get_intento(void);
        int dispersion_generica(T x);                                           //Función de dispersión genérica
        int exploracion_generica(T x,int intento);                              //Función de exploración genérica
        
        bool Buscar(T X);
        bool Insertar(T X);
        
        Celda<T>& operator[](int i);                                            //Operador que accede a los elementos de la tabla
        void exportar (void);

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

template <class T>
int TablaHash<T>::get_intento(void)
{
    return intento;
}

template <class T>
bool TablaHash<T>::Buscar(T X)
{
    intento = 1;
    int encontrado = 0;
    int pos = dispersion->h(X);

    if (!celdas[pos].Buscar(X))
    {
        while (!encontrado && intento <= tam)
        {
            int pos1 = exploracion->g(X,intento);
            encontrado = celdas[pos1].Buscar(X);
                if (encontrado == -2)
                    return false;
            intento++;
        }
        
    }
    
    else
        encontrado = true;
        
    return encontrado;
    
    
    
}

template <class T>
bool TablaHash<T>::Insertar(T X)
{
    intento = 1;
    bool insertado = false;
    int pos = dispersion->h(X);
    
    
    if (!celdas[pos].Insertar(X))
    {
        while (!insertado && intento <= tam)
        {
            int pos1 = exploracion->g(X,intento);
            insertado = celdas[pos1].Insertar(X);
            intento++;
        }
    }
    
    else
        insertado = false;
        
    return insertado;
}

template <class T>
void TablaHash<T>::exportar(void) 
{
    ofstream salida("salida.txt"); 
    for(int i = 0; i < tam; i++) 
    {
        for(int j = 0; j < celdas[i].get_sz();  j++)
	    {
            salida << setw(10) << celdas[i].get_dato(j) << " | ";
	    }
	    salida << endl << endl;
	}
	
   
}