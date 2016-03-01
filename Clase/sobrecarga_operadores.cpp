//Sobrecarga de operador [] para el vector

TDATO& operator[](void)
{
    return v_[pos];
}

TDATO& operator[](void) const //Procedimiento para vectores constantes.
{
    return v_[pos];
}

//Sobrecarga de operador *

TDATO operator*(const vector_t& v)
{
    TDATO prod = 0;
    for(int i = 0; i < sz_; i++)
    {
        prod+= v_[i] * v[i]
    }
    
    return prod;
}

//Sobrecarga del operador +

TDATO operator+(const vector_t& v)
{
    vector_t aux(sz_);
    for(int i = 0; i < sz_; i++)
    {
        aux[i] = v_[i] + v[i]
    }
    
    return prod;
}

//Sobrecarga del operador <

bool operator<(const vector& v)
{
    bool menor = true;
    int i = 0;
    while((i< sz_) && menor)
    {
        menor = v_[i] < v[i];
        i++;
    }
    return menor;
}

class matrix_t
{
    private:
        
        TDATO*  M_;
        int     m_;
        int     n_;
        
    public:
    
        matrix_t(void);
        matrix_t(int n, int m);
        int pos(int i, int j);
        void redimensiona(int i, int j);
        void crear_matrix(void);
        void destruye_matrix(void);
        TDATO& operator()(int i, int j) //Operador () similar al operador [], () Permite varias declaraciones.
        {
            return M_[pos(i,j)];
        }
        TDATO& operator()(int i, int j) const
        {
            return M_[pos(i,j)];
        }
        /*
        int main (void)
        {
            matrix_t A(10,10);
            A(1,1) = 25;
            A(1,2) = 36;
            A(1,3) = 49;
        }
        */
        ostream& operator <<(ostream& os)
        {
            for(int i = 1; i<=m_; i++)
            {
                for(int i = 1; i<=m_; i++)
                {
                    os << setw(10) << fixed << setprecision(4) << M_[pos(i,j)];
                }
                
                os << endl; 
            }
            return os;
        }
        
        istream& operator >>(istream& is)
        {
            is >> m_ >> n_;
            redimensiona(n_,m_);
            for(int i = 1; i<=m_; i++)
            {
                is >> M_[i];
            }
            return is;
        }
        
        //Las sobrecargas de operadores se pueden hacer en la clase o mediante funciones friend por fuera de la clase
        
        matrix_t operator A(const matrix_t& M)
        {
            matrix_t Aux(m_,M_.get_n());
            for(int i = 1; i<=m_; i++)
            {
                for(int i = 1; i<=m_; i++)
                {
                    TDATO aux1 = 0;
                    for(int k = i; k<=n_; k++)
                    {
                        aux1+= M_[pos(i,k)];
                        Aux(i,j) = aux1;
                    }
                }
            }
            return Aux;
        }
};