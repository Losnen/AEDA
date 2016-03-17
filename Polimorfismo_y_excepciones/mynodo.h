#pragma once
#include <iostream>
#include <cstdio>
#include <new>
#include <stdexcept>  

using namespace std;

template <class T>
class mynodo
{
    private:
        T dato_; 
        mynodo<T>* next_;
        
    public:
        mynodo(void);
        mynodo(T dato);
        ~mynodo(void);
        mynodo<T>* get_next(void);
        T get_dato(void);
        void set_next(mynodo<T>* next);
        void set_dato(T dato);
        ostream& write(ostream& os);
};

template <class T>
mynodo<T>::mynodo(void):
dato_(),
next_(NULL)
{}

template <class T>
mynodo<T>::mynodo(T dato):
dato_(dato),
next_(NULL)
{}

template <class T>
mynodo<T>::~mynodo(void)
{}


template <class T>
mynodo<T>* mynodo<T>::get_next(void)
{
    return next_;
}

template <class T>
T mynodo<T>::get_dato(void)
{
    return dato_;
}

template <class T>
void mynodo<T>::set_next(mynodo<T>* next)
{
    next_ = next;
}

template <class T>
void mynodo<T>::set_dato(T dato)
{
    dato_ = dato;
}

template <class T>
ostream& mynodo<T>::write(ostream& os)
{
    os << dato_ << " ";
}