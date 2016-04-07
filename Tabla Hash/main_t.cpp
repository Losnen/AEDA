#include <iostream>

#include "d_modulo.h"
#include "d_pseudo.h"
#include "e_cuadratica.h"
#include "e_doble.h"
#include "e_lineal.h"
#include "e_redisp.h"


using namespace std;

int main(void)
{
    Dispersion<int>* d = new Modulo<int>(5);
    Dispersion<int>* a = new Pseudo<int>(5);
    Exploracion<int>* b = new Cuadratica<int>(5,a);
    Exploracion<int>* c = new Doble<int>(5,a);
    Exploracion<int>* e = new Lineal<int>(5,a);
    Exploracion<int>* f = new Redisp<int>(5,a);
    
    cout << b->g(d->h(5),10) << endl; 
    cout << c->g(d->h(5),10) << endl; 
    cout << e->g(d->h(5),10) << endl; 
    cout << f->g(d->h(5),10) << endl;
    cout << b->g(a->h(5),10) << endl; 
    cout << c->g(a->h(5),10) << endl; 
    cout << e->g(a->h(5),10) << endl; 
    cout << f->g(a->h(5),10) << endl;

}