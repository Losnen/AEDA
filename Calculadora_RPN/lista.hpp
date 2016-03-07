#pragma once

#include <iostream>
using namespace std;

#include "nodo.hpp"

template <class TDATO>
class dll {
private:

        node<TDATO>* beginning_;
        node<TDATO>* end_;

 public:
        dll(void);
         ~dll(void);

        void insert_beginning(node<TDATO>* n);
        node<TDATO>* extract_beginning(void);

	    void insert_end(node<TDATO>* n);
	    node<TDATO>* extract_end(void);

        bool empty(void) const;	
	    ostream&  write(ostream& os) const;
};
    

template <class TDATO>
dll<TDATO>::dll(void):
beginning_(NULL),
end_(NULL){}


template <class TDATO>
dll<TDATO>::~dll(void) 
{
    while (beginning_ != NULL) 
    {
        node<TDATO>* aux = beginning_;
        beginning_ = beginning_->get_next();
        delete aux;
        }
}


template <class TDATO>	
bool dll<TDATO>::empty(void) const 
{
        return (beginning_ == NULL);
}



template <class TDATO>
void dll<TDATO>::insert_beginning(node<TDATO>* n)
{
   n->set_next(beginning_);
   n->set_prev(NULL);
    	
  if(end_ == NULL)
    	end_ = n;
   else
        beginning_->set_prev(n);
    	    
    beginning_ = n;
}


template <class TDATO>
node<TDATO>* dll<TDATO>::extract_beginning(void) 
{

   node<TDATO>* aux = beginning_;
   beginning_ = beginning_->get_next();
        
   aux->set_next(NULL);
   aux->set_prev(NULL);
        
   if (beginning_ == NULL)
        end_ = NULL;

        return aux;
}



template <class TDATO> 
void dll<TDATO>::insert_end(node<TDATO>* n)
{
    n->set_prev(end_);
    n->set_next(NULL);
    	
    if (end_ != NULL)
    	    end_->set_next(n);
    else
    	    beginning_ = n;
    	    
    end_ = n;
}


template <class TDATO>
node<TDATO>* dll<TDATO>::extract_end(void) 
{

        node<TDATO>* aux = end_;
        
        end_ = end_->get_prev();
        
        aux->set_next(NULL);
        aux->set_prev(NULL);
        
        if (end_ == NULL)
            beginning_ = NULL;
        else
            end_->set_next(NULL);

        return aux;
    } 


template <class TDATO>
ostream& dll<TDATO>::write(ostream& os) const 
{
    node<TDATO>* aux = beginning_;

    while (aux != NULL) 
    {
            aux->write(os);
            aux = aux->get_next();
    }
}
