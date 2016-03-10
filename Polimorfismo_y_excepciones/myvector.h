#pragma once
#include <iostream>


using namespace std;

template <class T>
class vector_t
{
    private:
        TDATO*  v_;
        int     sz_;
    
    public:
        
        vector_t(void);
        vector_t(int sz);
        vector_t(const vector_t& v);
        ~vector_t(void);
        void resize(int sz);
        int get_sz(void);
        int get_sz(void) const;
        TDATO& operator[](int pos);
        TDATO operator[](int pos) const;
        void write(void);
        
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
myvector<T>::vector_t(int sz)
{
    build(sz_);
}

template <class T>
myvector<T>::vector_t(const myvector<T>& v)
{
    build(v.get_sz());
    for (int i = 0; i<v.get_sz(); i++)
    {
        v_[i] = v[i];
    }
}

template <class T>
myvector<T>::~vector_t(void)
{
    
}

template <class T>
void myvector<T>::resize(int sz)
{
    
}

template <class T>
int myvector<T>::get_sz(void)
{
    
}

template <class T>
int myvector<T>::get_sz(void) const
{
    
}

template <class T>
T& myvector<T>::operator[](int pos)
{
    
}

template <class T>
T myvector<T>::operator[](int pos) const
{
    
}

template <class T>
void myvector<T>::write(void)
{
    
}

template <class T>        
void myvector<T>::build(int sz)
{
    
}

template <class T>
void myvector<T>::clean(void)
{
    
}