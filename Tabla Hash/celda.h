#pragma once
#include <iostream>

using namespace std;

template <class T>
class Celda
{
    private:
        
        T*      bloque;             //Vector 
        int     sz;                 //Tamaño del vector
        
    public:
        
        Celda(void);                //Constructor por defecto
        Celda(int tam);             //Constructor
        ~Celda(void);               //Destructor
        
        bool Buscar(T X);           //Funcionn de búsqueda en la celda
        bool Insertar(T X);         //Función de incersión en la celda
        
        T get_dato(int pos);        //Retorna el valor almacenado en bloque[pos]
        int get_sz(void);
        void resize(int tam);       //Reajusta el tamaño del vector
        bool full(void);            //Devuelve true si la celda está llena 
};


template <class T>
Celda<T>::Celda(void):
bloque(NULL),
sz(0)
{}

template <class T>
Celda<T>::Celda(int tam):
bloque(NULL),
sz(tam)
{
    bloque = new T[sz];
    
    for (int i = 0; i < sz; i++) 
    {
        bloque[i] = 0;
    }
}

template <class T>
Celda<T>::~Celda(void)
{
    if (bloque != NULL)
    {
        delete [] bloque;
        bloque = NULL;
        sz = 0;
    }
}

template <class T>
bool Celda<T>::Buscar(T X)
{
    for (int i = 0; i < sz; i++) 
    {
        if(bloque[i] == X)
        {
            return true;
        }
    }
    
    return false;
}

template <class T>
bool Celda<T>::Insertar(T X)
{
    for (int i = 0; i < sz; i++) 
    {
        if(bloque[i] == 0)
        {
            bloque[i] = X;
            return true;
        }
    }
    
    return false;
}

template <class T>
T Celda<T>::get_dato(int pos)
{
    return bloque[pos];
}

template <class T>
int Celda<T>::get_sz(void)
{
    return sz;
}

template <class T>
void Celda<T>::resize(int tam)
{
    sz = tam;
    bloque = new T[sz];
    
    for(int i = 0; i < tam; i++)
    { 
        bloque[i] = 0;
    }

}

template <class T>
bool Celda<T>::full(void)
{
    for(int i = 0; i < sz; i++)
    {
        if(bloque[i] == 0)
        {
            return false;
        }
    }
    return true;
}
