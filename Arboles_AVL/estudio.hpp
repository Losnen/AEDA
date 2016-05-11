#include "arbol.hpp"
#include "dni.hpp"
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <iomanip>

template <class XY>
void estudio(AVL<XY> A)
{
  int N=50;
  int P=50/2;
  
  for(int r=0;r<12;r++)
  {
     unsigned xyz=0;
     
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
     
     cout << endl;
     cout << " " <<  setw(24) << "N";cout << setw(15) << "P";cout << setw(15) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
     cout << "Busqueda  " <<  setw(15) << N;cout << setw(15) << P;cout << setw(14) << min[0]; cout << setw(15) << med[0]; cout << setw(15) << max[0] << endl;
     cout << "Inserción " <<  setw(15) << N;cout << setw(15) << P;cout << setw(14) << min[1]; cout << setw(15) << med[1]; cout << setw(15) << max[1] << endl;
     
     N*=2;
     P=N/2;
  }
}