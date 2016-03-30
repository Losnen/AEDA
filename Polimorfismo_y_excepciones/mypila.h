#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include "mylista.h"

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
	    T pop(void);
	    bool empty(void);
	    void clean(void);
	    ostream& write(ostream& os);
        ostream& imprime_numero(ostream& os);
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
T mypila<T>::pop(void)
{
    try
    {
        if(empty()) {throw "Lista está vacía"; }
        mynodo<T>* nodo_aux = l_.extract_begin();
        T aux = nodo_aux->get_dato();
        delete nodo_aux;
        return aux;
    } 
    catch(const char* a)
    {
        cerr << "ERROR: LA PILA ESTÁ VACÍA" << endl;
        exit(1);
    }
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
template <>
ostream& mypila<numero_t*>::imprime_numero(ostream& os)
{
    mynodo<numero_t*>* aux;
    while(!l_.empty())
    {
        aux = l_.extract_end();
        aux->get_dato()->toStream(cout);
        cout << " ";
    }
}
