#include "arbol.hpp"
#include "dni.hpp"
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include "estudio.hpp"

int main (void)
{
  ABB<DNI> A;
  
  system("clear");
  
  unsigned modo, tipo, N, P;
  bool comp, salir=false;
  char op;
  DNI data;
  int dato;

  
  cout << "******ÁRBOLES******" << endl;
  cout << "Eliga un Modo: " << endl;
  cout << "Demostración[0]" << endl;
  cout << "Estadísticas[1]" << endl;
  cin >> modo;
  
  if(modo==0)
  {
    
    while(!salir)
    { 
      cout << "\nEliga un método de entre los siguientes->" << endl;
      cout << "·Salir[0]." << endl;
      cout << "·Insertar clave[1]." << endl;
      cout << "·Eliminar clave[2]." << endl;
      cin >> tipo;
      
      switch(tipo)
      {
	case 0:
	  /****/
	  salir=true;
	  break;
      
	case 1:
	  /****/
	  
	  cout << "Insertar:  ";
	  cin >> dato;
	  data=dato;
	  A.Insertar(data);
	  /*A.Buscar(data, z);*/
	  A.imprimir();
	  break;
	  
	case 2:  
	  /****/
	  cout << "Eliminar:  ";
	  cin >> dato;
	  data=dato;
	  A.Eliminar(data);
	  /*A.Buscar(data, z);*/
	  A.imprimir();
	  break;
      
	default:
	  
	  cout << "Opción invalida, se saldrá del programa" << endl;
	  exit(1);
      }
      
    
    }
  }
  
   if(modo==1)
   {
     unsigned xyz=0;
     
     
     cout << "\n¿Que tamaño tendrá el árbol? "; cin >> N;
     cout << "\n¿Cuantas pruebas se harán? "; cin >> P;
     
     vector<DNI> banco(2*N,0);
     
     for(unsigned j=0;j<2*N;j++)
     {
       srand(time(NULL)+xyz);
       
       banco[j] = rand() % 30000000+50000000;	//Creamos numeros aleatorios entre 80.000.000 y 30.000.000 y los incertamos en el vector
       xyz++;
     }
     
     //INSERCIÓN
     
     for(unsigned i=0;i<N;i++)
     {
       A.Insertar(banco[i]);
     }
     
     vector<int> no(2,0);					//creamos un vector donde se guardarán el numero de comparaciones
     vector<unsigned> max(2,0); 				//vector donde se almacenarán los contenidos max de cada ordenación
     vector<unsigned> min(2,999999999);				//vector donde se almacenarán los contenidos min de cada ordenación
     vector< vector<double> > cont(2,vector<double> (P,0.0));	//vector de vectores de double donde se almacenará cada valor para luego hallar la media
     vector<double> med(2,0);
     
     for(unsigned k=0;k<P;k++)
     {
       A.Buscar(banco[N+rand()%(2*N+1-N)], no[1]);	//Inserción
       
       
       A.Buscar(banco[rand()%(N+1)], no[0]);		//Búsqueda
       
     
     
      for(int l=0;l<2;l++)					//coprobamos los nuevos valores
      {
	//cout << no[j] << endl;
	
	if(no[l]<min[l]) min[l]=no[l];
	if(no[l]>max[l]) max[l]=no[l];
	cont[l][k]=no[l];
	no[l]=0;
      }
     }
     
     for(int im=0;im<2;im++)		//calculamos la media
      {
	for(int jm=0;jm<P;jm++)
	{
	  med[im]+=cont[im][jm];
	}
	
	med[im]=(med[im]/P);
      }
     
     cout << setw(40) << "Número de comparaciones" << endl;
     cout << " " <<  setw(24) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
     cout << "Busqueda " << setw(15) << min[0]; cout << setw(15) << med[0]; cout << setw(15) << max[0] << endl;
     cout << "Inserción" << setw(15) << min[1]; cout << setw(15) << med[1]; cout << setw(15) << max[1] << endl;
     
     
   }
   
    if(modo==2)			//ESTUDIO
    {
      estudio<DNI>(A);
    }
}