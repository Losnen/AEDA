#pragma once
#include "nodo_t.h"
#include <iostream>
#include <cstdio>

using namespace std;

class lista_t
{
  private:
    nodo_t* head_;
    nodo_t* tail_;

  public:
    lista_t(void);
    ~lista_t(void);
    bool empty(void);
    void clean(void);
    void write(ostream& os);
    void insert_begin(nodo_t* aux);
    void insert_end(nodo_t* aux);
    nodo_t* extract_begin(void);
    nodo_t* extract_end(void);

};
