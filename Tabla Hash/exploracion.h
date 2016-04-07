#pragma once
#include <iostream>

using namespace std;

template <class T>
class Exploracion 
{
  public:

    virtual int g(T X, int intento) = 0; 
};