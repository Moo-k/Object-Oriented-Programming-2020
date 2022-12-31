#include <iostream>
using namespace std;
#include <string>

extern float add_op(float left, float right);
extern float subtract_op(float left, float right);
extern float arithmetic_ops(float left, float right, string op);

int main(){
	float left = 0;
	float right = 0;
	string op = "\0";
	
	cout << "Enter first number: ";
	cin >> left;
	
	cout << "Enter second number: ";
	cin >> right;	
	
	cout << "+ or -: ";
	cin >> op;
	
	if (op == "+"){
		cout << "The sum is " << arithmetic_ops(left,right,op) << endl;
	}	else if (op == "-"){
		cout << "The difference is "<< arithmetic_ops(left,right,op) << endl;
	}
	
	return 0;
}
