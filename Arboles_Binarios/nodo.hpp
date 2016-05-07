#pragma once

template <class A>
class nodoBB
{
public:
    //Atributos
  A dato;
  A clave;
  nodoBB *izdo;
  nodoBB *dcho;
    
  //Métodos
  nodoBB(A dat, A cl, nodoBB *iz=NULL, nodoBB *de=NULL):
  dato(dat), clave(cl), izdo(iz), dcho(de)
  {}
  
};