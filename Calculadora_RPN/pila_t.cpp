#include "pila_t.h"

pila_t::pila_t(void):
l_()
{}

pila_t::~pila_t(void)
{
    clean();
}

void pila_t::push(TDATO dato)
{
    l_.insert_begin(new nodo_t(dato));
}

char pila_t::pop(void)
{
    nodo_t* nodo_aux = (nodo_t*)(l_.extract_begin());
    TDATO aux = nodo_aux->get_dato();
    delete nodo_aux;
    return aux;
}

bool pila_t::empty(void)
{
    return l_.empty();
}

void pila_t::clean(void)
{
    l_.clean();
}

ostream& pila_t::write(ostream& os)
{
    l_.write(os);
    return os;    
}