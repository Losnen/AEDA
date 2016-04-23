#include <iostream>
#include <time.h>
#include <cstdlib>
#include "short.hpp"
#include "dni.hpp"

using namespace std;

int main(void)
{
  system("clear");
  
  unsigned modo, tipo, N, P;
  bool comp;
  char op;
  
  cout << "******ORDENACIÓN******" << endl;
  cout << "Eliga un Modo: " << endl;
  cout << "Demostración[0]" << endl;
  cout << "Estadísticas[1]" << endl;
  cin >> modo;
  
  if(modo==0)
  {
    cout << "\nEliga un método de entre los siguientes->" << endl;
    cout << "·Inserción[0]." << endl;
    cout << "·Selección[1]." << endl;
    cout << "·ShellSort[2]." << endl;
    cout << "·QuickSort[3]." << endl;
    cout << "·MergeSort[4]." << endl;
    cout << "·BubbleSort[5]." << endl;
    cout << "·ShakeSort[6]." << endl;
    cout << "·HeapSort[7]." << endl;
    cin >> tipo;
    
    if(tipo<5)
    {
      cout << "\nEl método selecionado le da la opción de ver las comparaciones y los resultados. ¿Desea activar esta opción?[s/n]"; cin >> op;
      
      if(op=='s')
      {
	comp=true;
      }
      
      if(op=='n')
      {
	comp=false;
      }
    }
    
    cout << "\n¿Que tamaño tendrá la secuencia? "; cin >> N;
    
    vector<DNI> banco(N,0);			//creamos un vector de tamaño N repleto de 0
  
    srand(time(NULL));
  
    for(unsigned i=0;i<N;i++) banco[i] = rand() % 30000000+50000000;	//Creamos numeros aleatorios entre 80.000.000 y 30.000.000 y los incertamos en el vector
    
    
    p5::ordenar<DNI>(banco, tipo, comp);
  }
  
  if(modo==1)
  {
    unsigned xyz=0;
    
    cout << "\n¿Que tamaño tendrá la secuencia? "; cin >> N;
    cout << "\n¿Cuantas pruebas se harán? "; cin >> P;
    
    vector< vector<DNI> > banco(P, vector<DNI> (N,0));
    
    for(unsigned j=0;j<P;j++)
    {
      srand(time(NULL)+xyz);
      
      for(unsigned k=0;k<N;k++) banco[j][k] = rand() % 30000000+50000000;	//Creamos numeros aleatorios entre 80.000.000 y 30.000.000 y los incertamos en el vector
       xyz++;
    }
    
    p5::estadistico(banco,P);
  }
}