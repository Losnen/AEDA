#pragma once
#include <iostream>
#include "nodo.hpp"
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

template <class A>
class ABB
{
private:
  
  nodoBB<A>* raiz;
  
public:
  //Operaciones Iniciales
  ABB() : raiz(NULL) {}
  ~ABB() { Podar(raiz); }
  void Podar(nodoBB<A>* &nodo);
  
  int niveles(void);
  
  //Búsqueda
  nodoBB<A>* Buscar(A clave_dada, int& a);
  nodoBB<A>* BuscarRama(nodoBB<A>* nodo, A clave_dada, int& a);
  
  //Inserción
  void Insertar(A clave_dada);
  void InsertarRama(nodoBB<A>* &nodo, A clave_dada);
  
  //Eliminación
  void Eliminar(A clave_dada);
  void EliminarRama(nodoBB<A>* &nodo, A clave_dada);
  
  //Sustituye
  void sustituye(nodoBB<A>* &eliminado, nodoBB<A>* &sust);
  
  //imprimir
  void imprimir(void);
  
};


template <class A>
void ABB<A>::Podar(nodoBB<A>* &nodo)
{
  if(nodo==NULL) return;
  Podar(nodo->izdo);
  Podar(nodo->dcho);
  delete nodo;
  nodo = NULL;
}

//Búsqueda
template <class A>
nodoBB<A>* ABB<A>::Buscar(A clave_dada, int& a)
{
  return BuscarRama(raiz, clave_dada, a);
}

template <class A>
nodoBB<A>* ABB<A>::BuscarRama(nodoBB<A>* nodo, A clave_dada, int& a)
{
  a++;
  if(nodo == NULL)
    return NULL;
  if(clave_dada == nodo->clave)
    return nodo;
  if(clave_dada < nodo->clave)
    return BuscarRama(nodo->izdo, clave_dada, a);
  return BuscarRama(nodo->dcho, clave_dada, a);
}

//Inserción
template <class A>
void ABB<A>::Insertar(A clave_dada)
{
  InsertarRama(raiz, clave_dada);
}

template <class A>
void ABB<A>::InsertarRama(nodoBB<A>* &nodo, A clave_dada)
{
  if(nodo==NULL)
    nodo=new nodoBB<A>(clave_dada, clave_dada);
  else if(clave_dada < nodo->clave)
    InsertarRama(nodo->izdo, clave_dada);
  else
    InsertarRama(nodo->dcho, clave_dada);
}
  
//Eliminación
template <class A>
void ABB<A>::Eliminar(A clave_dada)
{
  EliminarRama(raiz,clave_dada);
}
 
template <class A>
void ABB<A>::EliminarRama(nodoBB<A>* &nodo, A clave_dada)
{
  if(nodo==NULL) return;
  if(clave_dada < nodo->clave)
    EliminarRama(nodo->izdo, clave_dada);
  else if(clave_dada > nodo->clave)
    EliminarRama(nodo->dcho,clave_dada);
  else {    //clave_dada == nodo->clave
     
    nodoBB<A>* Eliminado=nodo;
    if(nodo->dcho == NULL)
      nodo = nodo->izdo;
    else if(nodo->izdo == NULL)
      nodo = nodo->dcho;
    else
      sustituye(Eliminado, nodo->izdo);
     
    delete(Eliminado);
   }
 }
 
//Sustituye
template <class A>
void ABB<A>::sustituye(nodoBB<A>* &eliminado, nodoBB<A>* &sust)
{
  if(sust->dcho != NULL)
    sustituye(eliminado, sust->dcho);
  else
  {
    eliminado->dato = sust->dato;
    eliminado->clave = sust->clave;
    eliminado = sust;
    sust=sust->izdo;
  }
}


template <class A>
int ABB<A>::niveles(void)
{
  int nv=0;
  nodoBB<A>* aux=raiz;
  
  while(aux->izdo!=NULL)
  {
    aux=aux->izdo;
    nv++;
  }
  
  return nv;
}

template <class A>
void ABB<A>::imprimir(void)
{
  nodoBB<A>* aux = raiz;
  int i=0;
  bool marca;
  int p;
  
  vector< nodoBB<A>* > vacio;
  
  vector< vector< nodoBB<A>* > > V(1);
  V[0]=vector< nodoBB<A>* >(1,aux);
  bool end=false;
  
  while(!end)
  {
    p=pow(2,i);
    
    V.push_back(vacio);
    
    for(int j=0;j<p;j++)
    {
      if(V[i][j]!=NULL)
      {
       V[i+1].push_back(V[i][j]->izdo);
       V[i+1].push_back(V[i][j]->dcho);
      }
      else
      {
	V[i+1].push_back(NULL);
	V[i+1].push_back(NULL);
      }
      
      end=true;
      for(int m=0;m<p;m++)
      {
	if(V[i][m]!=NULL)
	  end=false;
      }
     }
     i++;
   }
  
  for(int k=0;k<V.size();k++)
  {
    marca=false;
    for(int n=0;n<V[k].size();n++) if(V[k][n]!=NULL) marca=true;
    
    if(marca)
    cout << "NIVEL " << k << ": ";
    
    for(int l=0;l<V[k].size();l++)
    {
      if(marca)
      if((V[k][l]!=NULL))
	cout << "[" << V[k][l]->dato << "] ";
      else
	cout << "[.] ";
    }
    cout << endl;
  }
}











