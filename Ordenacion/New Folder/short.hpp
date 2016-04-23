#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;

namespace p5
{
//*************************(INSERCIÓN)*************************

template <class A>
void insercion(vector<A>& sec, bool comp, unsigned& no)
{
   
  for(int i = 1; i<sec.size();i++)
  {
    int j = i;
    A x = sec[i];
    sec[-1] = x;		//centinela
    
    while(x < sec[j-1])		//recorremos la parte ya "ordenada" para determinar la pos de inserción
    {
      
      sec[j] = sec[j-1];
      j--;
      
      no++;
    }
    
    if(comp)
    {
      cout << "\nElementos comparados: " << sec[j] << " " << x << endl;
    }
    
    sec[j] = x;
    
    if(comp)
    {
      cout << "Secuencia tras comparación: ";
      for(unsigned j2=0;j2<sec.size();j2++) cout << sec[j2] << " "; cout << endl;
    }
  }
  
  sec[-1]=0;
} 
  
//*************************(SELECCIÓN)*************************
  
template <class B>
void seleccion(vector<B>& sec, bool comp, unsigned& no)
{
  B x=0;
  
  for(int i=0;i<sec.size()-1;i++)	//buscamos el elemento de menor clave en la parte "no ordenada"
  {
    int min = i;
    
    for(int j=i+1;j<sec.size();j++)
    {
      if(sec[j]<sec[min])
      {
	min = j;
	no++;
      }
    }
    
    if(comp)
    {
      cout << "\nElementos comparados: " << sec[min] << " " << sec[i] << endl;
    }
    
    //intercambiamos el elemento de menor clave y el actual
    x = sec[min];
    sec[min]=sec[i];
    sec[i]=x;
    
    
    if(comp)
    {
      cout << "Secuencia tras comparación: ";
      for(unsigned j2=0;j2<sec.size();j2++) cout << sec[j2] << " "; cout << endl;
    }
  }
    
}
  
//*************************(SHELLSORT)*************************
  
template <class C>
void deltasort(int d, vector<C>& sec, int n, bool comp, unsigned& no)
{
  C x=0;
  int j=0;
  
  
  for(int i=d;i<n;i++)
  {
    x=sec[i];
    j=i;
    while((j>d-1)&&(x<sec[j-d]))
    {
      sec[j]=sec[j-d];
      j=j-d;
      no++;
    }
    
    if(comp && (sec[j]!=x))
    {
      cout << "\nElementos comparados: " << sec[j] << " " << x << endl;
    }
    
    
    if(sec[j]!=x)
    {
      sec[j]=x;
    
      if(comp)
      {
	cout << "Secuencia tras comparación: ";
	for(unsigned j2=0;j2<sec.size();j2++) cout << sec[j2] << " "; cout << endl;
      }
    }
  }
}
  
template <class D>
void shellsort(vector<D>& sec, double alph, bool comp, unsigned& no)
{
  int del = sec.size();
  
  while(del>alph)
  {
    del=del/2;
    deltasort(del,sec,sec.size(),comp, no);
  }
    
}
  
//*************************(QUICKSORT)*************************

template <class E>
void swap(E &a,E &b)
{
    int aux = a;
    a = b;
    b = aux;
}


template <class E>
int dividir(vector<E>& sec, int ini, int fin, bool comp, unsigned& no){
    int izq;
    int der;
    int pivot;
 
    pivot = sec[ini];
    izq = ini;
    der = fin;
 
    
    while (izq < der)			//Mientras no se cruzen los indices
    {
        while (sec[der] > pivot)
        {
            der--;
            no++;
        }
        while ((izq < der) && (sec[izq] <= pivot)){
            izq++;
            no++;
        }
 
        
        if(izq < der)					//si no se han cruzan intercambiamos
        {
            swap(sec[izq],sec[der]);
         
        }
    }
    
     if(comp)
    {
      cout << "\nElementos comparados: " << sec[der] << " " << sec[ini] << endl;
    }
    
    
    //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
    swap(sec[der],sec[ini]);
    
    
    if(comp)
    {
      cout << "Secuencia tras comparación: ";
      for(unsigned j2=0;j2<sec.size();j2++) cout << sec[j2] << " "; cout << endl;
    }
    
    //La nueva posicion del pivote
    return der;
}

template <class E>
void quicksort(vector<E>& sec, int ini, int fin, bool comp, unsigned& no)
{
  int pivot;
    if(ini < fin){
 
        pivot = dividir<E>(sec,ini, fin, comp, no);
         
        quicksort(sec, ini, pivot - 1,comp, no);  //ordeno la lista de los menores
        quicksort(sec, pivot + 1, fin, comp, no); //ordeno la lista de los mayores
    }
}
  
//*************************(MERGESORT)*************************

template <class G>
void mezcla(vector<G>& sec,vector<G> U,vector<G> V, bool comp, unsigned& no)
{
  int i=0;int j=0;
  
   if(comp)
    {
      cout << "\nElementos comparados(U y V): "<< endl;
      for(unsigned j1=0;j1<U.size();j1++) cout << U[j1] << " "; cout << endl;
      for(unsigned j2=0;j2<V.size();j2++) cout << V[j2] << " "; cout << endl;
    }
  
  for(int k=0;k<sec.size();k++)
  {
    if((i<U.size())&&(j<V.size()))
    {     
      if(U[i]<V[j])					//si el contenido de U es menor que el de V
      {
	sec[k]=U[i];					//ponemos ese elemnto en el vector del resultado
	i++;						//amunetamos la pos del iterador
	
	no++;
      }
      else						//si el contenido de U es mayor que el de V
      {
	sec[k]=V[j];					//ponemos ese elemnto en el vector del resultado
	j++;						//amunetamos la pos del iterador
	
      }
    }
    else
    {
      if(i>=U.size())
      {
	sec[k]=V[j];					//ponemos ese elemnto en el vector del resultado
	j++;
	
      }
      else
      {
	if(j>=V.size())
	{
	  sec[k]=U[i];					//ponemos ese elemnto en el vector del resultado
	  i++;
	  
	}
      }
    }
  }
  
  if(comp)
    {
      cout << "Secuencia tras comparación: ";
      for(unsigned j3=0;j3<sec.size();j3++) cout << sec[j3] << " "; cout << endl;
    }
  
}
  
template <class H>
void mergesort(vector<H>& sec, bool comp, unsigned& no)
{
  if(sec.size()>1)
  {
    vector<H> U(sec.begin(),(sec.begin()+sec.size()/2));		//creamos un vector con la primera mitad de sec
    vector<H> V((sec.begin()+sec.size()/2), sec.end());			//creamos un vector con la segunda mitad de sec
    
    mergesort(U, comp, no);							//llamada recursiva con la primera mitad
    mergesort(V, comp, no);							//llamada recursiva con la segunda mitad
    mezcla(sec,U,V, comp, no);							//luego mezclamos
    
  }  
}
  
//***********************************(OTROS)***********************************

//*************************(BUBBLESORT)*************************

template <class I>
void bubblesort(vector<I>& sec)
{
  I x;
  
  for(int i=1;i<sec.size();i++)
  {
    for(int j=sec.size()-1;j>=i;j--)
    {
      if(sec[j]<sec[j-1])			//si el elemento bubble topa con uno menor
      {
	x=sec[j-1];				//se intercambian
	sec[j-1]=sec[j];
	sec[j]=x;
      }
    }
  }
}


//*************************(SHAKESORT)*************************

template <class J>
void shakesort(vector<J>& sec)		//variación de la burbuja pero con dos recorridos(mejora)
{
  int ini=1;
  int fin=sec.size()-1;
  int cam = sec.size();
  
  J x;
  
  while(ini<fin)
  {
    for(int j=fin;j>=ini;j--)		//recorrido ascendente(bubble)
    {
      if(sec[j]<sec[j-1])
      {
	x=sec[j-1];
	sec[j-1]=sec[j];
	sec[j]=x;
	cam=j;
      }
    }
    ini=cam+1;
    for(int j=ini;j<=fin;j++)		//recorrido descendente(stone)
    {
      if(sec[j]<sec[j-1])
      {
	x=sec[j-1];
	sec[j-1]=sec[j];
	sec[j]=x;
	cam=j;
      }
    }
    fin=cam-1;
  }
}

//*************************(HEAPSORT)*************************
 
template <class K>
void baja(int i, vector<K>& sec, int n)
{
  K x=sec[i];
  int h, h1, h2;
  
  while(2*i<=n)
  {
    h1=2*i;
    h2=h1+1;
    if(h1==n)
    {
      h=h1;
    }
    else
    {
      if(sec[h1]>sec[h2])
      {
	
	h=h1;
	
      } else 
      {
	h = h2;
      }
    }
      
    if(sec[h]<=x) 
    {
      break;
    }
    else
    {
      sec[i]=sec[h];
      sec[h]=x;
      i=h;
    }
  }
}
 
template <class L>
void heapsort(vector<L>& sec)
{
  L x;
  
  for(int i=sec.size()/2;i>-1;i--)
  {
    baja<L>(i,sec,sec.size());
  }
  
  for(int i=sec.size()-1;i>1;i--)
  {
    x=sec[0];
    sec[0]=sec[i];
    sec[i]=x;
    baja<L>(0,sec,i-1);
  }
  swap(sec[0],sec[1]);
}
 
//*************************(HEAPSORT)*************************
 
template <class N>
void binsort(vector<N>& sec)
{
  int ini, fin, j, med;
  N x;
  
  
  for(int i=1;i<sec.size();i++)
  {
    j=i;
    x=sec[i];
    ini=0;fin=i-1;
    while(ini <=fin)
    {
      med=(ini+fin)/2;
      
      if(sec[med]<x) ini=med+1;
      else fin=med-1;
    }
    
    for(int k=i-1;k>=ini;k--) sec[k+1]=sec[k];
    sec[ini] = x;
  }
}
 
 
//*************************(RADIXSORT)*************************
 
/*template <class M> 
void radixSort(vector<M>& sec)
{
  if (sec.size() == 0) return;

    vector<M> buckets(10,0);    // assuming decimal numbers

    // Sort the array in place while keeping track of bucket starting indices.
    // If bucket[i] is meant to be empty (no numbers with i at the specified digit),
    // then let bucket[i+1] = bucket[i]

    for (int i = 0; i < 10; ++i)
    {
        radixSort(input + buckets[i], buckets[i+1] - buckets[i], digit+1);
    }
}*/
 
//*************************MENU****************************************
template <class XY>
void ordenar(vector<XY>& sec,int tipo,bool comp)
{
  vector<XY> aux(sec);
  
  //imprimimos el vector sin ordenar
  cout << "\nVECTOR SIN ORDENAR: ";
  for(int iv=0;iv<sec.size();iv++) cout << sec[iv] << " ";
  cout << endl;
  
  unsigned a=0;
  
  //ejecutamos la ordenación elegida
  switch(tipo)
  {
    case 0:
      /****/
      insercion(sec, comp,a);
      break;
  
    case 1:
      /****/
      seleccion(sec,comp,a);
      break;
      
    case 2:  
      /****/
      shellsort(sec,0.5,comp,a);
      break;
  
    case 3:    
      /****/
      quicksort(sec,0,sec.size()-1,comp,a);
      break;
  
    case 4:  
      /****/
      mergesort(sec,comp,a);
      break;
  
    case 5:    
      
      bubblesort(sec);
      break;
  
    case 6:    
      
      shakesort(sec);
      break;
  
    case 7:    
      
      heapsort(sec);
      break;
      
    case 8:    
      
      binsort(sec);
      break;
      
    default:
      
      cout << "Opción invalida, se saldrá del programa" << endl;
      exit(1);
  }
  
  
  cout << "\nVECTOR ORDENADO: ";
  for(int io=0;io<sec.size();io++) cout << sec[io] << " ";
  cout << "\n" << endl;
  
}


template <class YX>
void estadistico(vector< vector<YX> >& sec, unsigned P)
{
  
  
  /*for(int i20=0;i20<P;i20++)
  {
    for(int z20=0;z20<P;z20++)
    {
      cout << sec[i20][z20] << " ";
    }
    cout << endl;
  }*/
  vector<YX> aux;
  
  vector<unsigned> no(5,0);					//creamos un vector donde se guardarán el numero de comparaciones
  vector<unsigned> max(5,0); 					//vector donde se almacenarán los contenidos max de cada ordenación
  vector<unsigned> min(5,999999999);				//vector donde se almacenarán los contenidos min de cada ordenación
  vector< vector<double> > cont(5,vector<double> (P,0.0));	//vector de vectores de double donde se almacenará cada valor para luego hallar la media
  vector<double> med(5,0);					//vector donde se almacenará la media de cada prueba
  
  for(int i=0;i<P;i++)						//ejecutamos cada ordenación para cada prueba
  {
    aux=sec[i];							//creamos un auxiliar para almacenar el vector a ordenar
     //for(int j20=0;j20<5;j20++) cout << no[j20] << endl;
    
    insercion(aux, false,no[0]);
    aux=sec[i];							//reiniciamos el auxiliar
    
    seleccion(aux, false, no[1]);
    aux=sec[i];							//reiniciamos el auxiliar
    
    shellsort(aux,0.5,false,no[2]);
    aux=sec[i];							//reiniciamos el auxiliar
    
    quicksort(aux,0,sec[i].size()-1,false,no[3]);
    aux=sec[i];							//reiniciamos el auxiliar
    
    mergesort(aux,false,no[4]);
    aux=sec[i];							//reiniciamos el auxiliar
    
    for(int j=0;j<5;j++)					//coprobamos los nuevos valores
    {
      //cout << no[j] << endl;
      
      if(no[j]<min[j]) min[j]=no[j];
      if(no[j]>max[j]) max[j]=no[j];
      cont[j][i]=no[j];
      no[j]=0;
    }
    
  }
  
  for(int im=0;im<5;im++)		//calculamos la media de cada tipo de ordenación
  {
    for(int jm=0;jm<P;jm++)
    {
      med[im]+=cont[im][jm];
    }
    
    med[im]=(med[im]/P);
  }
  
  
  //IMRPIMIOS LAS ESTADÍSTICAS
  cout << setw(40) << "Número de comparaciones" << endl;
  cout << " " <<  setw(24) << "Mínimo"; cout << setw(15) << "Medio"; cout << " " << setw(15) << "Máximo" << endl;
  cout << "Inserción" << setw(15) << min[0]; cout << setw(15) << med[0]; cout << setw(15) << max[0] << endl;
  cout << "Selección" << setw(15) << min[1]; cout << setw(15) << med[1]; cout << setw(15) << max[1] << endl;
  cout << "ShellSort" << setw(15) << min[2]; cout << setw(15) << med[2]; cout << setw(15) << max[2] << endl;
  cout << "QuickSort" << setw(15) << min[3]; cout << setw(15) << med[3]; cout << setw(15) << max[3] << endl;
  cout << "MergeSort" << setw(15) << min[4]; cout << setw(15) << med[4]; cout << setw(15) << max[4] << endl;
  
  cout << endl;
  
  
  /*for(int i21=0;i21<P;i21++)
  {
    for(int z21=0;z21<P;z21++)
    {
      cout << sec[i21][z21] << " ";
    }
    cout << endl;
  }*/
  
}




}//end namespace