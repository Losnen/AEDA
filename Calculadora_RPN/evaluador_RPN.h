#include <cstring>
#include <cstdlib>
#include "pila_t.h"


class evaluador_RPN_t 
{

  private:
   	pila_t pila;
  public: 
	
	evaluador_RPN_t(void);
	~evaluador_RPN_t(void);
	int eval(char* expres);
	bool es_operando(char* expres);



};

