#pragma once

#include "lista.hpp"
#include <iostream>
using namespace std;


template <class TDATO>
class pila {
private:
        dll<TDATO> list_;

public:
        pila(void);
        ~pila(void);

	    void push(TDATO dato);
	    TDATO pop(void);
	    
	    bool empty(void);

        ostream& write(ostream& os);
};


template <class TDATO>
pila<TDATO>::pila(void):
list_()
{}

template <class TDATO>
pila<TDATO>::~pila(void)
{}

template <class TDATO>
void pila<TDATO>::push(TDATO dato)
{
        list_.insert_beginning(new node<TDATO>(dato));
}
 
template <class TDATO>   
TDATO pila<TDATO>::pop(void)
{
   node<TDATO>* n_aux = (node<TDATO>*)(list_.extract_beginning());
        
    TDATO aux = n_aux->get_value();
        
    delete n_aux;
        
    return aux;
}
    
    
template <class TDATO>
bool pila<TDATO>::empty(void)
{
    return list_.empty();
}

template <class TDATO>
ostream& pila<TDATO>::write(ostream& os)
{
    list_.write(os);
    return os;
}
