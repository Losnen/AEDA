#include "evaluador_RPN.h"

evaluador_RPN_t::evaluador_RPN_t(void):
pila()
{}

evaluador_RPN_t::~evaluador_RPN_t(void)
{}



int evaluador_RPN_t::eval(char* expres)
{
	char* pch = NULL;
	pch = strtok(expres," ");
	int aux = 0;
	int right = 0;
	int left = 0; 
	


	while(pch!= NULL){

		if(pch[0] == '+')
		{
			right= pila.pop();
		    left= pila.pop();
			pila.push(left + right);

		}

		else if(pch[0] == '-')
		{
			right= pila.pop();
			left= pila.pop();
			pila.push(left-right);
		}

		else if(pch[0] == '*')
		{
			right= pila.pop();
			left= pila.pop();
			pila.push(left*right);
		}

		else if(pch[0] == '/')
		{
			right= pila.pop(); 
			left= pila.pop();
			pila.push(left/right);

		}
		
		else if(pch[0] == '%')
		{
			right= pila.pop(); 
			left= pila.pop();
			pila.push(left % right);
		}
		
		else
		{
			aux = atoi(pch);
			pila.push(aux);

		}
		pch = strtok(NULL," ");
	}

	return pila.pop();
}


bool evaluador_RPN_t::es_operando(char* expres)
{
	if( ((*expres)>= '0') && ((*expres)<= '9') )
	return true;

	else
	return false;
}
