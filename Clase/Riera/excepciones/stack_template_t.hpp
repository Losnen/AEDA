#pragma once
#include "sll_t.hpp"

#include <iostream>
#include <iomanip>

#include <exception>

#define STACK_LIMIT_DEFAULT 100

using namespace std;

class stack_exception_t: public exception
{
};

class empty_stack_exception: public stack_exception_t
{
public:
	virtual const char* what(void) const throw ()
	{
		return "Stack template exception: empty stack";
	}
};

class stack_overflow_exception: public stack_exception_t
{
public:
	virtual const char* what(void) const throw ()
	{
		return "Stack template exception: stack overflow";
	}
};

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

	int stack_limit_;

public:
	stack_template_t(void): 
	sll_t(),
	stack_limit_(STACK_LIMIT_DEFAULT) {}

	stack_template_t(int stack_limit): 
	sll_t(),
	stack_limit_(stack_limit) {}

	virtual ~stack_template_t(void) {}

	void push(T dato)
	{
		if (size() >= stack_limit_)
			throw stack_overflow_exception();

		stack_item_t<T>* ptr = new stack_item_t<T>(dato);
		
		if (!ptr)
			throw bad_alloc();

		push_back(ptr);
  }
		
	T pop(void)
	{
		if (empty())
			throw empty_stack_exception();

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
