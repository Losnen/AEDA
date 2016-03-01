#include <iostream>
#include "lista_t.h"

typedef int TDATO;
using namespace std;

class pila_t 
{
    private:
        lista_t l_;

    public:
        pila_t(void);
        ~pila_t(void);
	    void push(TDATO dato);
	    char pop(void);
	    bool empty(void);
	    void clean(void);
        ostream& write(ostream& os);
};