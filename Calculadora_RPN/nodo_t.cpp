#include "nodo_t.h" 
 
        nodo_t::nodo_t(void):
        next_(NULL),
        dato_(0)
        {}
        
        nodo_t::nodo_t(TDATO dato):
        next_(NULL),
        dato_(dato)
        {}
        
        nodo_t::~nodo_t(void)
        {}
        
        nodo_t* nodo_t::get_next(void)
        {
            return next_;
        }
        
        TDATO nodo_t::get_dato(void)
        {
            return dato_;
        }
        
        void nodo_t::set_next(nodo_t* next)
        {
            next_ = next;
        }
        
        void nodo_t::set_dato(TDATO dato)
        {
            dato_ = dato;
        }
        
        ostream& nodo_t::write(ostream& os)
        {
            	os << dato_ << " ";
        }