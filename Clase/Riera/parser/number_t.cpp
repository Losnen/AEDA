#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

enum {
	integer_num,
	real_num,
	rational_num,
	complex_num
};

template <class T> 
T maxi (T a, T b) {
	return a > b? a: b;
}

class number_t {
private:
	double* info_;
	int     sz_;
	int     num_type_;
public:
	number_t(void):
	info_(NULL),
	sz_(0),
	num_type_(-1)
	{}

	number_t(int sz, int num_type):
	info_(NULL),
	sz_(sz),
	num_type_(num_type)
	{
		info_ = new double [sz_];

		for(int i = 0; i < sz_; i++)
			info_[i] = 0.0;
	}

	number_t(const number_t& number):
	info_(NULL),
	sz_(number.sz_),
	num_type_(number.num_type_)
	{
		info_ = new double [sz_];

		for(int i = 0; i < sz_; i++)
			info_[i] = number.info_[i];
	}

	~number_t(void){
		if (info_){
			delete [] info_;
			info_ = NULL;
		}
	}

	void set_num (int pos, double val){
		info_[pos] = val;
	}

	double get_num (int pos) const{
		if (pos >= sz_)
			return 0.0;
		else
			return info_[pos];
	}

	number_t suma(const number_t& number) const
	{
		number_t aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

		for(int i = 0; i < aux.sz_; i++)
			aux.info_[i] = get_num(i) + number.get_num(i);

		return aux;		
	}

	number_t resta(const number_t& number) const 
	{
		number_t aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

		for(int i = 0; i < aux.sz_; i++)
			aux.info_[i] = get_num(i) - number.get_num(i);

		return aux;		
	}

	number_t multiplica(const number_t& number) const
	{
		number_t aux(maxi(sz_ , number.sz_), maxi(num_type_, number.num_type_));

		if (aux.sz_ == 1)
			aux.info_[0] = info_[0] * number.info_[0];
		else if (aux.num_type_ == complex_num){
			aux.info_[0] = get_num(0) * number.get_num(0) -  get_num(1) * number.get_num(1); 
			aux.info_[1] = get_num(0) * number.get_num(1) +  get_num(1) * number.get_num(0);
		}

		return aux;		
	}

	ostream& write(ostream& os) const
	{
		switch (num_type_) {
			case integer_num:
			os << setw(11) << fixed << setprecision(0) << get_num(0);
			break;
			case real_num:
			os << setw(11) << fixed << setprecision(3) << get_num(0);
			break;
			case complex_num:
			os << setprecision(3);
			os << get_num(0);
			os << "+";
			os << get_num(1);
			os << "i";
			break;
		}
	}
};

number_t operator+(const number_t& a, const number_t& b)
{
	return a.suma(b);
}

number_t operator-(const number_t& a, const number_t& b)
{
	return a.resta(b);
}

number_t operator*(const number_t& a, const number_t& b)
{
	return a.multiplica(b);
}

ostream& operator<< (ostream& os, const number_t& number)
{
	return number.write(os);
}

class integer_t: public number_t{
public:
	integer_t(void):
	number_t(1, integer_num)
	{
		set_num(0,0);	
	}

	integer_t(double num):
	number_t(1, integer_num)
	{
		set_num(0,trunc(num));	
	}

	integer_t(string num):
	number_t(1, integer_num)
	{
		set_num(0, trunc(stod(num)));	
	}

	virtual ~integer_t(void) {}
};

class real_t: public number_t{
public:
	real_t(void):
	number_t(1, real_num)
	{
		set_num(0, 0);	
	}

	real_t(double num):
	number_t(1, real_num)
	{
		set_num(0, num);	
	}

	real_t(string num):
	number_t(1, real_num)
	{
		set_num(0, stod(num));	
	}

	virtual ~real_t(void) {}
};


class complex_t: public number_t{
public:
	complex_t(void):
	number_t(2, complex_num)
	{
		set_num(0, 0);
		set_num(1, 0);	
	}

	complex_t(double re, double im):
	number_t(2, complex_num)
	{
		set_num(0, re);
		set_num(1, im);	
	}

	complex_t(string num):
	number_t(2, complex_num)
	{
		string::size_type pos = num.find("i");
		string suma = num.substr (0, pos);

		pos = suma.find("+");
		string re = suma.substr (0, pos);
		string im = suma.substr (pos);

		set_num(0, stod(re));
		set_num(1, stod(im));	
	}

	virtual ~complex_t(void) {}
};


int main(void)
{
	string complex("5+7.45i");
	string real   ("5.67889");
	string integer("4536569");

	integer_t a(integer);
	real_t    b(real);
	complex_t c(complex);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	number_t d = a + b;
	number_t e = c - b;
	number_t f = c * b;

	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
} 


