#include <iostream>
#include <stdlib.h>

#include "myvector.h"
#include "mylista.h"
#include "mypila.h"
#include "mycola.h"

#include "numero.h"
#include "enteros.h"
#include "racionales.h"
#include "reales.h"
#include "complejos.h"


using namespace std;

int main (void)
{
    myvector<numero_t*> A(4);
   	mylista<numero_t*> 	L;
   	mypila<numero_t*> 	pila; 
	mycola<numero_t*> 	cola;
   	
   	A[0] = new entero(1);
	L.insert_begin(new mynodo<numero_t*>(new entero(1)));
	pila.push(new entero(1));
	cola.put(new entero(1));

	A[1] = new racional(1,2);
	L.insert_begin(new mynodo<numero_t*>(new racional(1,2)));
	pila.push(new racional(1,2));
	cola.put(new racional(1,2));


	A[2] = new real(2.0);
	L.insert_begin(new mynodo<numero_t*>(new real(2.0)));
	pila.push(new real(2.0));
	cola.put(new real(2.0));
		
	A[3] = new complejo(1.5,2.76);
	L.insert_begin(new mynodo<numero_t*>(new complejo(1.5,2.76)));
	pila.push(new complejo(1.5,2.76));
	cola.put(new complejo(1.5,2.76));
   	
   	numero_t* n1 = new racional(7,3);
   	numero_t* n2 = new real(8.3);
   	numero_t* n3 = new complejo(3.3,2);
   	numero_t* n4 = new entero(1);
   	
	cout << "AEDA Práctica 3: Polimorfismo y excepciones" << endl;
   	cout << "Procedimiento toEntero" << endl;
   	cout << n4->toEntero() << endl;
   	cout << n1->toEntero() << endl;
   	cout << n2->toEntero() << endl;
   	cout << n3->toEntero() << endl;
   	
   	cout << "Procedimiento toReal" << endl;
   	cout << n4->toReal() << endl;
   	cout << n1->toReal() << endl;
   	cout << n2->toReal() << endl;
   	cout << n3->toReal() << endl;
   	
   	cout << "Procedimiento toRacional" << endl;
   	cout << n4->toRacional() << endl;
   	cout << n1->toRacional() << endl;
   	cout << n2->toRacional() << endl;
   	cout << n3->toRacional() << endl;
   	
   	cout << "Procedimiento toComplejo" << endl;
   	cout << n4->toComplejo() << endl;
   	cout << n1->toComplejo() << endl;
   	cout << n2->toComplejo() << endl;
   	cout << n3->toComplejo() << endl;
   	

	
	cout << "Vector de números" << endl;
	A.imprime_numero(cout);
	cout << endl;
	cout << "Lista de números" << endl;
	L.imprime_numero(cout);
	cout << endl;
	cout << "Pila de números" << endl;
	pila.imprime_numero(cout);
	cout << endl;
	cout << "Cola de números" << endl;
	cola.imprime_numero(cout);
	cout << endl;
}