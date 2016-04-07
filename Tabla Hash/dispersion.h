#pragma once
#include <iostream>

using namespace std;

template <class T>
class Dispersion 
{
  public:

    virtual int h(T X) = 0; 
};