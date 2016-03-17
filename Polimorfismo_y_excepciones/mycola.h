#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "mylista.h"


using namespace std;

template <class T>
class mycola 
{
    private:
        mylista<T> l_;
        
    public:
        mycola(void);
        ~mycola(void);
        void put(T dato);
        T get(void);
        bool empty(void);
        void clean(void);
        ostream& write(ostream& os);
    
};

template <class T>
mycola<T>::mycola(void):
l_()
{}

template <class T>
mycola<T>::~mycola(void)
{
    clean();
}

template <class T>
void mycola<T>::put(T dato)
{
    try
    {
        l_.insert_begin(new  mynodo<T>(dato));
    } 
    catch(bad_alloc& ba)
    {
        cerr << ba.what() << endl;
        exit(1);
    }

}

template <class T>
T mycola<T>::get(void)
{
    try
    {
        if(empty()) {throw "L está vacía"; }
        mynodo<T>* nodo_aux = l_.extract_end();
        T aux = nodo_aux->get_dato();
        delete nodo_aux;
        return aux;
    } 
    catch(const char* a)
    {
        cerr << "ERROR LA COLA ESTÁ VACÍA" << endl;
        exit(1);
    }
    
}

template <class T>
bool mycola<T>::empty(void)
{
    return l_.empty();
}

template <class T>
void mycola<T>::clean(void)
{
    l_.clean();
}

template <class T>
ostream& mycola<T>::write(ostream& os)
{
   l_.write(os);
    return os; 
}