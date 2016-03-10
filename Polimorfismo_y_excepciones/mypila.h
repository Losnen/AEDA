#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "tlista.hpp"

using namespace std;

template <class T>
class mypila
{
    private:
    
        mylista<T> l_;

    public:
        mypila(void);
        ~mypila(void);
	    void push(T dato);
	    char pop(void);
	    bool empty(void);
	    void clean(void);
	    ostream& write(ostream& os);
};

template <class T>
mypila<T>::mypila(void):
l_()
{}

template <class T>
mypila<T>::~mypila(void)
{
  clean();  
}

template <class T>
void mypila<T>::push(T dato)
{
    l_.insert_begin(new mynodo<T>(dato));
}

template <class T>
char mypila<T>::pop(void)
{
    mynodo<T>* nodo_aux = l_.extract_begin();
    T aux = nodo_aux->get_dato();
    delete nodo_aux;
    return aux;
}

template <class T>
bool mypila<T>::empty(void)
{
    return l_.empty();
}

template <class T>
void mypila<T>::clean(void)
{
    l_.clean();
}

template <class T>
ostream& mypila<T>::write(ostream& os)
{
    l_.write(os);
    return os;   
}