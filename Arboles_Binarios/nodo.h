#pragma once

template <class T>
class nodoBB
{
    public:

        T dato;
        T clave;
        nodoBB *izdo;
        nodoBB *dcho;

        nodoBB(T dat, T cl, nodoBB *iz=NULL, nodoBB *de=NULL):
        dato(dat), 
        clave(cl), 
        izdo(iz),
        dcho(de)
        {}
  
};