#pragma once

template <class A>
class nodoAVL
{
public:
    //Atributos
  A dato;
  A clave;
  int bal;
  nodoAVL *izdo;
  nodoAVL *dcho;
    
  //Métodos
  nodoAVL(A dat, A cl, nodoAVL *iz=NULL, nodoAVL *de=NULL):
  dato(dat), clave(cl), izdo(iz), dcho(de), bal(0)
  {}
  
};