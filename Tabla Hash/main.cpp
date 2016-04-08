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
    Dispersion<DNI>* hxp;
    Exploracion<DNI>* gxp;
/* switch(hx)
    {
        case 0:
            return(dispersion_modulo(x));
        break;
        case 1:
            return(dispersion_aleatoria(x));
        break;
        default:
            cout << "Dispersión inválida" << endl;
            exit(0);
        break;
    } 
        
            switch(gx)
    {
        case 0:
            return(exploracion_lineal(x,intento));
        break;
        case 1:
            return(exploracion_cuadratica(x,intento));
        break;
        case 2:
            return(exploracion_doble(x,intento));
        break;
        case 3:
            return(exploracion_redispersion(x,intento));
        break;
        default:
            cout << "Exploración inválida" << endl;
            exit(0);
        break;
    }
    }*/    
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
    cout << "1.Cuadrática" << endl;
    cout << "2.Dispersión doble" << endl;
    cout << "3.Re-dispersión" << endl;
    cout << "Opción: "; 
    cin >> gx;
    
    switch(hx)
    {
        case 0:
            hxp = new Modulo<DNI>(nCeldas);
        break;
        case 1:
            hxp = new Pseudo<DNI>(nCeldas);
        break;
        default:
            cout << "Dispersión inválida" << endl;
            exit(0);
        break;
    } 
        
    switch(gx)
    {
        case 0:
            gxp = new Lineal<DNI>(nCeldas,hxp); 
        break;
        case 1:
            gxp = new Cuadratica<DNI>(nCeldas,hxp); 
        break;
        case 2:
            gxp = new Doble<DNI>(nCeldas,hxp); 
        break;
        case 3:
            gxp = new Redisp<DNI>(nCeldas,hxp); 
        break;
        default:
            cout << "Exploración inválida" << endl;
            exit(0);
        break;
    }
    
    TablaHash<DNI> H(nCeldas, nBloques, gxp, hxp);
    
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
            while(!H[H.exploracion_generica(banco[i],intento)].Insertar(banco[i]))
            {
                intento++;
    	    }
    	    clave_cnt++;
    	    intento = 0;	
        }
        
        cout << "Clave_cnt: " << clave_cnt << endl;
        
    //Apartado 5
    int maxB = 0; 
    int minB = 999999999;
    vector<double> B(nPruebas);
    double acuB = 0.0;
    
    srand(time(NULL));
    
    intento=0;
    for(int i = 0; i < nPruebas; i++)
    {
        int x = rand()%(N/2);
    
        while(!H[H.exploracion_generica(banco[x], intento)].Buscar(banco[x]))
        {
            intento++;
        }
    
        if((intento + 1) < minB) 
        {
            minB = (intento + 1);
        }
        
        if((intento + 1) > maxB) 
        {
            maxB = (intento + 1);
        }
    
        B[i] = (intento + 1);
    
        intento = 0;
    }
    
    double aux = 0.0;
    
    for(int i = 0; i < nPruebas; i++) 
    {
        aux+= B[i];
    }
    acuB = aux/nPruebas;
    
    //Apartado 6
    int maxI = 0; 
    int minI = 999999999;
    vector<double> C(nPruebas);
    double acuI = 0.0;
    
    srand(time(NULL));
    
    intento=0;
    for(int i = 0; i < nPruebas; i++)
    {
        int z = rand()%((N/2)+1)+(N/2);
        
        // BANCO = 100
        // N = 50
        // 0 - 50
        // Z = 51 - 100
        
    
        while(!H[H.exploracion_generica(banco[z], intento)].Buscar(banco[z]))
        {
            intento++;
            if(!H[H.exploracion_generica(banco[z], intento)].full()) 
            {
                break;
            }
        }
    
        if((intento + 1) < minI)
        {
            minI = (intento + 1);
        }
        
        if((intento + 1) > maxI) 
        {
            maxI = (intento + 1);
        }
        
        C[i] = (intento + 1);
    
        intento = 0;
    }
    
    
    double aux2 = 0.0;
    
    for(int i = 0; i < nPruebas; i++)
    {
        aux2+= C[i];
    }
    acuI = aux2/nPruebas;
    
    cout << endl << endl;
    cout << "Celdas"; 
    cout << setw(12) << "Bloques";
    cout << setw(20) << "Exploración";
    cout << setw(12) << "Carga"; 
    cout << setw(12) << "Pruebas" << endl;
    
    cout << nCeldas; 
    cout << setw(12) << nBloques;
    
    switch(gx)
    {
        case 0:
            cout << setw(22) << "Lineal";
        break;
        case 1:
            cout << setw(22) << "Cuadrática";
        break;
        case 2:
            cout << setw(22) << "Dispersión Dobe";
        break;
        case 3:
            cout << setw(22) << "Re-dispersión";
        break;
    }
    
    cout << setw(12) << factor; 
    cout << setw(12) << nPruebas << endl;
    cout << endl << endl;
    
    cout << setw(40) << "Número de comparaciones" << endl;
    cout << " " <<  setw(24) << "Mínimo"; 
    cout << setw(15) << "Medio"; 
    cout << " " << setw(15) << "Máximo" << endl;
    cout << "Búsquedas" << setw(15) << minB; 
    cout << setw(15) << acuB; 
    cout << setw(15) << maxB << endl;
    cout << "Inserción" << setw(15) << minI; 
    cout << setw(15) << acuI; 
    cout << setw(15) << maxI << endl;
    cout << endl;
}