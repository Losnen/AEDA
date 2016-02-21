#include <iostream>
#include <stdlib.h>

#include "vector_t.h"
#include "lista_t.h"
#include "pila_t.h"
#include "cola_t.h"


using namespace std;

int main (void)
{
	vector_t A(10);
	vector_t B(10);
	lista_t L;
	pila_t pila; 
	cola_t cola;
	
    int opcion = 9;
   	do
  	{
  		cout << "Práctica 1 AEDA: Implementación de estructuras de datos" << endl;
	    cout << "MENU:" << endl;
	    cout << "1 Vector" << endl;
	    cout << "2 Lista" << endl;
	    cout << "3 Pila" << endl;
	    cout << "4 Cola" << endl;
	    cout << "0 Salir"<< endl;
	    cout << "Introduzca una opción: ";
	    cin >> opcion;
	
	    switch(opcion)
	    {
	      case 0:
	    	exit(0);
	      break;
	      case 1:
	        system("clear");
		    cout << "Vector: " << endl;
		   
		    for(int i = 0; i<10; i++)
		    {
		        A[i] = i;
		        B[i] = i;
		    }
		
		    A.write();
		    cout << "Producto escalar A*A= " << A.escalar(B) << endl; 
	      break;
	      case 2:
	    	//Lista
	    	system("clear");
		    cout << "Lista: " << endl;
		    
		    if(L.empty())
		        cout << "Lista Vacía" << endl;
		    
		    cout << "Rellenando Lista" << endl;
			for(int i=0;i<10;i++)
			{
				L.insert_begin(new nodo_t(i));
			}
		    if(!L.empty())
		        cout << "Lista llena" << endl;
		        
			L.write(std::cout);
			L.clean();
			
		cout << endl;
	      break;
	      case 3:
	    	//Pila
			system("clear");
			cout << "Insertando en la Pila" << endl; 
			for(int i = 0; i < 10; i++)
			{ 
				pila.push(i);
			}
			cout << "Extrayendo de la pila " << endl;
			pila.write(std::cout);
			pila.clean();
			cout << endl;
	      break;
	      case 4:
	        //Cola
	        system("clear");
			cout << "Insertando en la cola" << endl;
			for(int i = 0; i < 10; i++)
			{ 
				cola.put(i);
			}
			cout << "Extrayendo de la cola" << endl;
			while(!cola.empty()) 
				cout << cola.get() << " ";	
			
			cout << endl;
			cola.clean();
	      break;
	      
	      default:
	      	system("clear");
	        cout << "Opción incorrecta." <<endl;
	      break;
	    }
	  }while(opcion!=-1);
}