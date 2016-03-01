#pragma once
#include <iostream>
#include <cstdio>

using namespace std;

typedef int TDATO;

class nodo_t
{
    private:
        TDATO dato_; 
        nodo_t* next_;
        
    public:
        nodo_t(void);
        nodo_t(TDATO dato);
        ~nodo_t(void);
        nodo_t* get_next(void);
        TDATO get_dato(void);
        void set_next(nodo_t* next);
        void set_dato(TDATO dato);
        ostream& write(ostream& os);
};