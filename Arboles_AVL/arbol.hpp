#pragma once
#include <iostream>
#include "nodo.hpp"
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

template <class A>
class AVL
{
private:
  
  nodoAVL<A>* raiz;
  
public:
  //Operaciones Iniciales
  AVL() : raiz(NULL) {}
  ~AVL() { Podar(raiz); }
  void Podar(nodoAVL<A>* &nodo);

  void imprimir(void);
  
  //Búsqueda
  nodoAVL<A>* Buscar(A clave_dada, int& a);
  nodoAVL<A>* BuscarRama(nodoAVL<A>* nodo, A clave_dada, int& a);
  
  //ROTACIÓN II
  void rotacion_II(nodoAVL<A>* &nodo);
  //ROTACIÓN DD
  void rotacion_DD(nodoAVL<A>* &nodo);
  //ROTACIÓN ID
  void rotacion_ID(nodoAVL<A>* &nodo);
  //ROTACIÓN DI
  void rotacion_DI(nodoAVL<A>* &nodo);
  
  //INSERTA Y BALANCEA
  void Insertar(A ClaveDada);
  void inserta_bal(nodoAVL<A>* &nodo, nodoAVL<A>* nuevo, bool& crece);
  void insert_re_balancea_izda(nodoAVL<A>* &nodo, bool& crece);
  void insert_re_balancea_dcha(nodoAVL<A>* &nodo, bool& crece);
  
  //ELIMINACIÖN CON REBALANCEO
  void Eliminar(A clave_dada);
  void elimina_rama(nodoAVL<A>* &nodo, A ClaveDada, bool& decrece);
  void sustituye(nodoAVL<A>* &eliminado, nodoAVL<A>* &sust, bool &decrece);
  void eliminar_re_balancea_izda(nodoAVL<A>* &nodo, bool& decrece);
  void eliminar_re_balancea_dcha(nodoAVL<A>* &nodo, bool& decrece);
};

template <class A>
void AVL<A>::Podar(nodoAVL<A>* &nodo)
{
  if(nodo==NULL) return;
  Podar(nodo->izdo);
  Podar(nodo->dcho);
  delete nodo;
  nodo = NULL;
}

template <class A>
nodoAVL<A>* AVL<A>::Buscar(A clave_dada, int& a)
{
  return BuscarRama(raiz, clave_dada, a);
}

template <class A>
nodoAVL<A>* AVL<A>::BuscarRama(nodoAVL<A>* nodo, A clave_dada, int& a)
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

//ROTACIÓN II
template <class A>
void AVL<A>::rotacion_II(nodoAVL<A>* &nodo)
{
  nodoAVL<A>* nodo1 = nodo->izdo;
  nodo->izdo=nodo1->dcho;
  nodo1->dcho=nodo;
  
  if(nodo1->bal==1)
  {
    nodo->bal=0;
    nodo1->bal=0;
    
  } else
  {
    nodo->bal=1;
    nodo1->bal=-1;
  }
  nodo=nodo1;
}

//ROTACIÓN DD
template <class A>
void AVL<A>::rotacion_DD(nodoAVL<A>* &nodo)
{
  nodoAVL<A>* nodo1=nodo->dcho;
  nodo->dcho = nodo1->izdo;
  nodo1->izdo = nodo ;
  
  if (nodo1->bal == -1) 
  {
    nodo->bal = 0;
    nodo1->bal = 0;
  }
  else 
  { // nodo1->bal == 0
    nodo->bal = -1;
    nodo1->bal = 1;
  }
  nodo = nodo1;
}

//ROTACIÓN ID
template <class A>
void AVL<A>::rotacion_ID(nodoAVL<A>* &nodo)
{
    nodoAVL<A>* nodo1 = nodo->izdo;
    nodoAVL<A>* nodo2 = nodo1->dcho;
    nodo->izdo = nodo2->dcho;
    nodo2->dcho = nodo;
    nodo1->dcho = nodo2->izdo;
    nodo2->izdo = nodo1;
    
    if (nodo2->bal == -1)
      nodo1->bal = 1;
    else nodo1->bal = 0;
    if (nodo2->bal == 1)
      nodo->bal = -1;
    else nodo->bal = 0;
    nodo2->bal = 0;
    nodo = nodo2;
}

//ROTACIÓN DI
template <class A>
void AVL<A>::rotacion_DI(nodoAVL<A>* &nodo)
{
    nodoAVL<A>* nodo1 = nodo->dcho;
    nodoAVL<A>* nodo2 = nodo1->izdo;
    nodo->dcho = nodo2->izdo;
    nodo2->izdo = nodo;
    nodo1->izdo = nodo2->dcho;
    nodo2->dcho = nodo1;
    
    if (nodo2->bal == 1)
      nodo1->bal = -1;
    else nodo1->bal = 0;
    if (nodo2->bal == -1)
      nodo->bal = 1;
    else nodo->bal = 0;
    nodo2->bal = 0;
    nodo = nodo2;
}

  
//INSERTA Y BALANCEA
template <class A>
void AVL<A>::Insertar(A ClaveDada)
{
    nodoAVL<A>* nuevo = new nodoAVL<A>(ClaveDada,ClaveDada, 0);
    bool crece = false;
    inserta_bal(raiz, nuevo, crece);
}

template <class A>
void AVL<A>::inserta_bal(nodoAVL<A>* &nodo, nodoAVL<A>* nuevo, bool& crece)
{
    if (nodo == NULL) {
      nodo = nuevo;
      crece = true;
    }
    else if (nuevo->clave < nodo->clave) {
      inserta_bal(nodo->izdo,nuevo,crece);
      if (crece) insert_re_balancea_izda(nodo, crece);
    }
    else {
      inserta_bal(nodo->dcho,nuevo,crece);
      if (crece) insert_re_balancea_dcha(nodo, crece);
    }
}

template <class A>
void AVL<A>::insert_re_balancea_izda(nodoAVL<A>* &nodo, bool& crece)
{
  switch (nodo->bal) {
    case -1: 	nodo->bal = 0;
		crece = false;
		break;
		
    case 0: 	nodo->bal = 1;
		break;

    case 1: 	nodoAVL<A>* nodo1 = nodo->izdo;
		if (nodo1->bal == 1)
		  rotacion_II(nodo);
		else rotacion_ID(nodo);
		  crece = false;
  }
}

template <class A>
void AVL<A>::insert_re_balancea_dcha(nodoAVL<A>* &nodo, bool& crece)
{
  switch (nodo->bal) {
    case 1: 	nodo->bal = 0;
		crece = false;
		break;
		
    case 0: 	nodo->bal = -1;
		break;
		
    case -1: 	nodoAVL<A>* nodo1 = nodo->dcho;
		if (nodo1->bal == -1)
		  rotacion_DD(nodo);
		else rotacion_DI(nodo);
		  crece = false;
  }
}

  
//ELIMINACIÖN CON REBALANCEO
template <class A>
void AVL<A>::Eliminar(A clave_dada)
{
  bool decrece = false;
  elimina_rama( raiz, clave_dada, decrece);
}

template <class A>
void AVL<A>::elimina_rama(nodoAVL<A>* &nodo, A ClaveDada, bool& decrece)
{
  if (nodo == NULL) return;
  if (ClaveDada < nodo->clave) {
    elimina_rama(nodo->izdo,ClaveDada,decrece);
    if (decrece)
      eliminar_re_balancea_izda(nodo,decrece);
  }
  else if (ClaveDada > nodo->clave) {
    elimina_rama(nodo->dcho,ClaveDada,decrece);
    if (decrece)
      eliminar_re_balancea_dcha(nodo,decrece);
  }
  else { // clave_dada == nodo->clave
    nodoAVL<A>* Eliminado = nodo;
    if (nodo->izdo == NULL) {
      nodo = nodo->dcho;
      decrece = true;
    }
    else if (nodo->dcho == NULL) {
      nodo = nodo->izdo;
      decrece = true;
    }
    else {
      sustituye(Eliminado,nodo->izdo,decrece);
      if (decrece)
	eliminar_re_balancea_izda(nodo,decrece);
    }
    delete Eliminado;
  }
}

template <class A>
void AVL<A>::sustituye(nodoAVL<A>* &eliminado, nodoAVL<A>* &sust, bool &decrece)
{
  if (sust->dcho != NULL) {
    sustituye(eliminado, sust->dcho, decrece);
    if (decrece)
      eliminar_re_balancea_dcha(sust, decrece);
  }
  else {
    eliminado->dato = sust->dato;
    eliminado->clave = sust->clave;
    eliminado = sust;
    sust = sust->izdo;
    decrece = true;
  }
}

template <class A>
void AVL<A>::eliminar_re_balancea_izda(nodoAVL<A>* &nodo, bool& decrece)
{
  switch (nodo->bal) {
    case -1: 	{nodoAVL<A>* nodo1 = nodo->dcho;
		if (nodo1->bal > 0)
		  rotacion_DI(nodo);
		else {
		  if (nodo1->bal == 0)
		    decrece = false;
		  rotacion_DD(nodo);
		}
		break;}
		
    case 0: 	nodo->bal = -1;
		decrece = false;
		break;
		
    case 1: 	nodo->bal = 0;
  }
}

template <class A>
void AVL<A>::eliminar_re_balancea_dcha(nodoAVL<A>* &nodo, bool& decrece)
{
  switch (nodo->bal) {
    case 1: 	{nodoAVL<A>* nodo1 = nodo->izdo;
		if (nodo1->bal < 0)
		  rotacion_ID(nodo);
		else {
		  if (nodo1->bal == 0)
		    decrece = false;
		  rotacion_II(nodo);
		}
		break ;}
		
    case 0: 	nodo->bal = 1;
		decrece = false;
		break;
		
    case -1: 	nodo->bal = 0;
  }
}



template <class A>
void AVL<A>::imprimir(void)
{
  nodoAVL<A>* aux = raiz;
  int i=0;
  bool marca;
  int p;
  
  vector< nodoAVL<A>* > vacio;
  
  vector< vector< nodoAVL<A>* > > V(1);
  V[0]=vector< nodoAVL<A>* >(1,aux);
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











