#include <iostream>
#include <string>

#include "sll_t.hpp"

using namespace std;

enum token_types{
	t_operand,
	t_operator,
	t_err
};

const char* token_type_str [] {
	"OPERANDO",
	"OPERADOR",
	"ERROR"
};

enum token_id{
	t_integer,
	t_real,
	t_rational,
	t_complex,
	t_plus,
	t_minus,
	t_mult,
	t_div
};

const char* token_id_str [] {
	"ENTERO",
	"REAL",
	"RACIONAL",
	"COMPLEJO",
	"+",
	"-",
	"x",
	"/"
};

class parser_item_t: public sll_item_t {
private:
	int    token_type_;
	int    token_id_;
	string item_;
public:
	parser_item_t(int token_type, int token_id, const string& item):
	sll_item_t(),
	token_type_(token_type),
	token_id_(token_id),
	item_(item) {}

	~parser_item_t(void) {}

	virtual void write(ostream& os)
	{
		os << " < " << token_type_str[token_type_] << ", " << token_id_str[token_id_] << ", " << item_ << " > "; 
	}
};


class parser_t: public sll_t 
{
private:

	bool is_number(const string& s)
	{
		return ( ((s[0] == '-') && isdigit(s[1])) || isdigit(s[0]) );
	}

	bool is_complex(const string& s)
	{
		size_t found = s.find("i");
		
		return is_number(s) && (found != string::npos);
	}

	bool is_real(const string& s)
	{
		size_t found1 = s.find(".");
		size_t found2 = s.find("E");
		size_t found3 = s.find("e");
		
		return is_number(s) && ((found1 != string::npos) || (found2 != string::npos) || (found3 != string::npos));
	}

	bool is_operator(const string& s)
	{
		size_t sz = s.size();

		return ((sz == 1) && ((s[0] == '-') || (s[0] == '+') || (s[0] == '*') || (s[0] == '/')));
	}	

	void insert_token(const string& item)
	{

		if (is_operator(item)){
			switch (item[0]){
			case '+':
				push_back(new parser_item_t(t_operator, t_plus, item));
				break;
			case '-':
				push_back(new parser_item_t(t_operator, t_minus, item));
				break;
			case '*':
				push_back(new parser_item_t(t_operator, t_mult, item));
				break;
			case '/':
				push_back(new parser_item_t(t_operator, t_div, item));
				break;

			}
		}
		else
			if (is_complex(item)){	
				push_back(new parser_item_t(t_operand, t_complex, item));
			} else {
				if (is_real(item)){	
					push_back(new parser_item_t(t_operand, t_real, item));
				}
				else if (is_number(item)){
						push_back(new parser_item_t(t_operand, t_integer, item)); 
				}
				else{
						push_back(new parser_item_t(t_err, t_err, item)); 
				}			
			}
	}

public:
	parser_t(void):
	sll_t() {}

	virtual ~parser_t(void) {}

	void read(istream& is){
		
		string item;

		while (!is.eof()){
			
			getline(is >> ws, item, ' ');
		
			insert_token(item);
		}

		write(cout);
	}
};


