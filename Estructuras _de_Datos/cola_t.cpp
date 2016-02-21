#include "cola_t.h"


cola_t::cola_t(void):
l_()
{}

cola_t::~cola_t(void)
{
    clean();
}

void cola_t::put(TDATO dato)
{
    l_.insert_begin(new nodo_t(dato));
}

TDATO cola_t::get(void)
{
    nodo_t* nodo_aux = (nodo_t*)(l_.extract_end());
    TDATO aux = nodo_aux->get_dato();
    delete nodo_aux;
    return aux;
}

bool cola_t::empty(void)
{
    return l_.empty();
}

void cola_t::clean(void)
{
    l_.clean();
}

ostream& cola_t::write(ostream& os)
{
    l_.write(os);
    return os;
}
    