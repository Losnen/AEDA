#include <iostream>
#include "tabla.h"
#include "dni.h"

using namespace std;

int main (void)
{
    int nCeldas = -1;
    int nBloques = -1;
    int hx = -1;
    int gx = -1;
    int nPruebas = -1;
    double factor = 0.0;
    double fCarga = 0.0;
    int minimo = 99999999; 
    int acumulado = 0;
    int maximo = 0;
    
    //Apartado 1    
    cout << "AEDA Práctica 4: Tablas Hash" << endl;
    cout << "Introduzca el número de celdas de la tabla: ";
    cin >> nCeldas;
    
    cout << "Introduzca el número de bloques por celda: ";
    cin >> nBloques;
    
    cout << "Elige una función de dispersión: " << endl;
    cout << "0. Módulo" << endl;
    cout << "1. Pseudo-aleatoria" << endl;
    cout << "Opción: "; 
    cin >> hx;

    cout << "Elige una función de exploracion: " << endl;
    cout << "0.Lineal" << endl;
    cout << "1.Cuadrática[" << endl;
    cout << "2.Dispersión doble" << endl;
    cout << "3.Re-dispersión" << endl;
    cout << "Opción: "; 
    cin >> gx;

    TablaHash<DNI> H(nCeldas, nBloques, gx, hx);
    
    //Apartado 2
    cout << "Introduzca el factor de carga (Decimal entre  0 y 1): "; 
    cin >> factor;
    
    cout << "Introduzca el número de pruebas: "; 
    cin >> nPruebas;
    
    //Apartado 3
    int N = 2 * (factor * nCeldas * nBloques);
    srand(time(NULL));
    vector<DNI> banco(N,0);
  
    for(int i = 0; i < N; i++) 
    {
        banco[i] = rand() % 30000000+50000000;
    }
    
    //Apartado 4  
    int intento = 0;
    int clave_cnt = 0;
    
        for(int i = 0; i < (N/2); i++) 
        {
            while(!H[H.exploracion_generica(banco[i],intento)].Insertar(banco[i]))	            //Mientras no pueda insertar en la tabla
            {
                intento++;                                                                      //Aumentamos el intento
    	    }
    	    clave_cnt++;
    	    intento = 0;	
        }
        
        cout << "Clave_cnt: " << clave_cnt << endl;
        
    //Apartado 5
    for (int i = 0; i < nPruebas; i++) 
    {
        while(!H[H.exploracion_generica(banco[i],intento)].Insertar(banco[i]))	            //Mientras no pueda insertar en la tabla
        {
                intento++;                                                                      //Aumentamos el intento
    	}
    }
}