#pragma once

#include <iostream>
using namespace std;


template <class TDATO>
class node
{
private:

    TDATO value_;
    node<TDATO>* next_;
    node<TDATO>* prev_;
public:
        node(void);
        node(TDATO value);
        ~node(void);

	    void set_next(node<TDATO>* next);
	    node<TDATO>* get_next(void) const;
	    
	    void set_prev(node<TDATO>* prev);
	    node<TDATO>* get_prev(void) const;	
	    
	    
	     void set_value(TDATO value);
	    TDATO get_value(void) const;
	    
        ostream& write(ostream& os);

};

template <class TDATO>
node<TDATO>::node(void):
next_(NULL),
prev_(NULL),
value_(0)
{}
        
template <class TDATO>        
node<TDATO>::node(TDATO value):
next_(NULL),
value_(value)
{}
        
template <class TDATO>        
node<TDATO>::~node(void){}
        
        
template <class TDATO>
node<TDATO>* node<TDATO>::get_next(void) const
{
    return next_;
}
    
template <class TDATO>
TDATO node<TDATO>::get_value(void) const
{
    return value_;
}

template <class TDATO>
void node<TDATO>::set_next(node<TDATO>* next)
{
    next_ = next;
}

template <class TDATO>
void node<TDATO>::set_prev(node<TDATO>* prev)
{
		prev_ = prev;
}

template <class TDATO>
node<TDATO>* node<TDATO>::get_prev(void) const
{
		return prev_;
}


template <class TDATO>
void node<TDATO>::set_value(TDATO value)
{
    value_ = value;
}

template <class TDATO>
ostream& node<TDATO>::write(ostream& os)
{
    os << value_ << " ";
}