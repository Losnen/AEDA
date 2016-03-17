#pragma once
#include <iostream>
#include <new>
#include <stdexcept>  


#include "numero.h"

using namespace std;

template <class T>
class myvector
{
    private:
        T*      v_;
        int     sz_;
    
    public:
        
        myvector(void);
        myvector(int sz);
        myvector(const myvector<T>& v);
        ~myvector(void);
        void resize(int sz);
        int get_sz(void);
        int get_sz(void) const;
        T& operator[](int pos);
        T operator[](int pos) const;
        void write(void);
        ostream& imprime_numero(ostream& os);
        
        private:
        void build(int sz);
        void clean(void);
    
};

template <class T>
myvector<T>::myvector(void):
v_(NULL),
sz_(0)
{}

template <class T>
myvector<T>::myvector(int sz):
sz_(sz)
{
    build(sz);
}

template <class T>
myvector<T>::myvector(const myvector<T>& v)
{
    build(v.get_sz());
    for (int i = 0; i<v.get_sz(); i++)
    {
        v_[i] = v[i];
    }
}

template <class T>
myvector<T>::~myvector(void)
{
    clean();
}

template <class T>
void myvector<T>::resize(int sz)
{
    clean();
    sz_ = sz;
    build(sz_);
}

template <class T>
int myvector<T>::get_sz(void)
{
    return sz_;
}

template <class T>
int myvector<T>::get_sz(void) const
{
    return sz_;
}

template <class T>
T& myvector<T>::operator[](int pos)
{
    try
    {
        if((pos > sz_) || (pos < 0)) {throw "out of range";}
        
        return v_[pos];
		
	}
	catch(const char* a)
	{
		cerr << "Error al obtener el elemento ya que la posición está fuera de rango." << endl;
		exit(1);
	}
}

template <class T>
T myvector<T>::operator[](int pos) const
{
    try
    {
        if((pos > sz_) || (pos < 0)) {throw "out of range";}
        
        return v_[pos];
		
	}
	catch(const char* a)
	{
		cerr << "Error al obtener el elemento ya que la posición está fuera de rango." << endl;
		exit(1);
	}
}

template <class T>
void myvector<T>::write(void)
{
    cout << "Tamaño: " << get_sz() << endl;
    for(int i = 0; i<10; i++)
    {
        cout << v_[i] << " ";
    }
    cout << endl;
}

template <class T>        
void myvector<T>::build(int sz)
{
    try
    {
        v_ = new T [sz];
    }
    catch (bad_alloc& ba)
    {
        cerr << ba.what() << endl;
        exit(1);
    }
    
}

template <class T>
void myvector<T>::clean(void)
{
    if (v_ != NULL)
    {
        delete [] v_;
        v_ = NULL;
        sz_ = 0;
    }
}

template <>
ostream& myvector<numero_t*>::imprime_numero(ostream& os)
{
    for(int i = 0; i<sz_;i++) 
    {
        v_[i]->toStream(os);
        cout << " ";
    }
	return os;
}

