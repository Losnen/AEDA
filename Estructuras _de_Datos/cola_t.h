#include "lista_t.h"

typedef int TDATO;
using namespace std;

class cola_t 
{
    private:
        lista_t l_;
        
    public:
        cola_t(void);
        ~cola_t(void);
        void put(TDATO dato);
        TDATO get(void);
        bool empty(void);
        void clean(void);
        ostream&write(ostream& os);
    
};