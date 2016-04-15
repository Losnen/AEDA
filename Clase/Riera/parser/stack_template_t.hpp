#pragma once
#include "sll_t.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

template <class T>
class stack_item_t: public sll_item_t {
private:
	T dato_;
public:
	stack_item_t(T dato):
	sll_item_t(),
	dato_(dato){}

	T get_dato(void) {return dato_;}

	virtual ~stack_item_t(void) {}
}; 


template <class T>
class stack_template_t: public sll_t{

public:
	stack_template_t(void): 
	sll_t() {}

	virtual ~stack_template_t(void) {}

	void push(T dato)
	{
		push_back(new stack_item_t<T>(dato));
  }
		
	T pop(void)
	{
		stack_item_t<T>* dato_ptr = (stack_item_t<T>*)(pop_back());

		T dato = dato_ptr->get_dato();
		delete dato_ptr;

		return dato;
	}
	
	bool empty(void)
	{
		return sll_t::empty();
  }

	//void write(ostream& os);

};
