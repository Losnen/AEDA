#include <iostream>
#include "stack_template_t.hpp"

using namespace std;

int main(void)
{
	try{
		stack_template_t<int> Stack;
	
		cout << Stack.pop() << endl;
	}
	catch (exception& e){
		cout << e.what() << endl;
	}	


	try{
		stack_template_t<int> Stack(5);
	
		for(int i = 0; i < 6; i++)
			Stack.push(i);
	}
	catch (exception& e){
		cout << e.what() << endl;
	}
}
