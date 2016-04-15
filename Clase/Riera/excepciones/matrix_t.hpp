#pragma once 

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <exception>

using namespace std;


class matrix_t_exception
{
public:
  virtual const char * what () const throw () = 0;
};

class low_index_exception : public matrix_t_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Run time error in class 'matrix_t': low index";
  }
};

class high_index_exception : public matrix_t_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Run time error in class 'matrix_t': low index";
  }
};


class bad_size_exception : public matrix_t_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Run time error in class 'matrix_t': bad size of matrix";
  }
};

class out_of_mem_exception : public matrix_t_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Run time error in class 'matrix_t': out of memory";
  }
};

class writing_empty_matrix_exception : public matrix_t_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Run time error in class 'matrix_t': trying to write empty matrix";
  }

};

template <class T>
class matrix_t
{
private:
        int m_;
        int n_;
        
        T* v_;
        
public:
        matrix_t(void):
        m_(0),
        n_(0),
        v_(NULL) {}
        
        matrix_t(int m, int n):
        m_(m),
        n_(n),
        v_(NULL) {
                
	  try 
	  {
		build();
	  }
	  catch(bad_size_exception& e)
	  {
	    m_ = 0;
	    n_ = 0;
	    cout << e.what() <<  endl;
	  }
	  catch(out_of_mem_exception& e)
	 {
	    m_ = 0;
	    n_ = 0;
	    cout << e.what() <<  endl;
	 }
            }
        
        ~matrix_t(void)
        {
            destroy();
        }
        
        void resize(int m, int n)
        {
            destroy();
            m_ = m; n_ = n_;

	  try 
	  {
            build();
	  }
	  catch(bad_size_exception& e)
	  {
	    m_ = 0;
	    n_ = 0;
	    cout << e.what() <<  endl;
	  }
	  catch(out_of_mem_exception& e)
	 {
	    m_ = 0;
	    n_ = 0;
	    cout << e.what() <<  endl;
	 }
        }
        
        T& operator() (int i, int j)
        {

	if ((i < 1) || (j < 1))
		throw low_index_exception();

	if ((i > m_) || (j > n_))
		throw low_index_exception();
            
            return v_[pos(i,j)];
        }

        T operator() (int i, int j) const
        {
	if ((i < 1) || (j < 1))
		throw low_index_exception();

	if ((i > m_) || (j > n_))
		throw low_index_exception();        
    
            return v_[pos(i,j)];
        }        
        
        int get_m(void) const 
        {
            return m_;
        }
        
        int get_n(void) const
        {
            return n_;
        }
        
        ostream& write(ostream& os) const
        {

	    if ((m_ == 0) || (n_ == 0))
		throw writing_empty_matrix_exception();

            os << setw(4) << m_ << endl;
            os << setw(4) << n_ << endl;
            os << endl;
            
             for(int i = 1; i <= m_; i++){
                 for(int j = 1; j <= n_; j++)
                          os << v_[pos(i, j)] << " ";
                     
                os << endl;
             }      

            return os;
        }

        istream& read(istream& is)
        {
             destroy();
            
            is >> m_;
            is >> n_;
            
	  try 
	  {
            build();
	  }
	  catch(bad_size_exception& e)
	  {
	    m_ = 0;
	    n_ = 0;
	    cout << e.what() <<  endl;
	    return is;
	  }
	  catch(out_of_mem_exception& e)
	 {
	    m_ = 0;
	    n_ = 0;
	    cout << e.what() <<  endl;
	    return is;
	 }
            
             for(int i = 1; i <= m_; i++)
                 for(int j = 1; j <= n_; j++)
                        is >> v_[pos(i, j)];
            
            return is;
        }
   
        int pos(int i, int j) const
        {
            return (i -1)* n_ + j - 1;
        }
     
private:
        
        void build(void)
        {
	    if ((m_ <= 0) || (n_ <= 0))
		throw bad_size_exception();

            v_ = new T [m_ * n_];

	    if (v_ == NULL)
                throw out_of_mem_exception();
        }
        
        void destroy(void)
        {
            if (v_)
                delete  [] v_;
        }
} ;

template <>
ostream&  matrix_t<int>::write(ostream& os) const
{
    if ((m_ == 0) || (n_ == 0))
	throw writing_empty_matrix_exception();

    os << setw(4) << m_ << endl;
    os << setw(4) << n_ << endl;
    os << endl;
    
     for(int i = 1; i <= m_; i++){
         for(int j = 1; j <= n_; j++)
                  os << setw(5) << v_[pos(i, j)] << " ";
             
        os << endl;
     }      

    return os;
}

template <>
ostream&  matrix_t<double>::write(ostream& os) const
{
    if ((m_ == 0) || (n_ == 0))
	throw writing_empty_matrix_exception();

    os << setw(4) << m_ << endl;
    os << setw(4) << n_ << endl;
    os << endl;
    
     for(int i = 1; i <= m_; i++){
         for(int j = 1; j <= n_; j++)
                 os << setw(10)<< fixed << setprecision(4) << v_[pos(i, j)] << " ";
             
        os << endl;
     }      

    return os;
}

template <class T>
ostream& operator<<(ostream& os, const matrix_t<T>& M)
{
	  try {
	    M.write(os);
	  }
	  catch(writing_empty_matrix_exception& e)
	  {
	    cout << e.what() <<  endl;
	  }
	return os;
}

template <class T>
istream& operator>>(istream& is, matrix_t<T>& M)
{
	M.read(is);
	return is;
}



