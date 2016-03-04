#pragma once

#include "tlista.hpp"
#include <iostream>
using namespace std;


template <class T>
class pila {
private:
        dll<T> list_;

public:
        pila(void);
        ~pila(void);

	    void push(T dato);
	    T pop(void);
	    
	    bool empty(void);

        ostream& write(ostream& os);
};


template <class T>
pila<T>::pila(void):
list_()
{}

template <class T>
pila<T>::~pila(void)
{}

template <class T>
void pila<T>::push(T dato)
{
        list_.insert_beginning(new node<T>(dato));
}
 
template <class T>   
T pila<T>::pop(void)
{
   node<T>* n_aux = (node<T>*)(list_.extract_beginning());
        
    T aux = n_aux->get_value();
        
    delete n_aux;
        
    return aux;
}
    
    
template <class T>
bool pila<T>::empty(void)
{
    return list_.empty();
}

template <class T>
ostream& pila<T>::write(ostream& os)
{
    list_.write(os);
    return os;
}
