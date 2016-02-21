#include "lista_t.h"

lista_t::lista_t(void):
head_(NULL),
tail_(NULL)
{}

lista_t::~lista_t(void)
{
	clean();
}

bool lista_t::empty(void)
{
    if(head_ == NULL)
        return true;
    else
        return false;
}

void lista_t::clean(void)
{
	while (head_ != NULL) 
	{
       	nodo_t* aux = head_;
        head_ = head_->get_next();
        delete aux;
    }
}

void lista_t::write(ostream& os)
{
    nodo_t* aux = head_;
    while(aux != NULL)
    {
        aux->write(os);
        aux= aux->get_next();
    }
}


void lista_t::insert_begin(nodo_t* aux)
{
	if(empty())
	{
        head_ = aux;
        tail_ = aux;
	}
	else 
	{ 
        aux->set_next(head_);
	    head_=aux;
	}
}

void lista_t::insert_end(nodo_t* aux)
{
	if(empty())
	{
	    head_= aux;
	    tail_=aux;
	}
	else 
	{
	    tail_->set_next(aux);
	    tail_=aux;
	}
}

nodo_t* lista_t::extract_begin(void){
	if(head_==tail_)
	{
		nodo_t* aux=head_;
		head_=NULL;
		tail_=NULL;
		return aux;
	}
	else
	{
		nodo_t* aux = head_;
		head_=head_->get_next();
		return aux;
	}
}

nodo_t* lista_t::extract_end(void)
{
	if(head_==tail_)
	{
		nodo_t* aux=head_;
		head_=NULL;
		tail_=NULL;
		return aux;
	}
	else
	{
		nodo_t* aux=head_;
		while(aux->get_next() != tail_)
			aux=aux->get_next();
	    
	    tail_= aux;
	    aux=aux->get_next();
	    tail_->set_next(NULL);
	    return aux;
	}
}


