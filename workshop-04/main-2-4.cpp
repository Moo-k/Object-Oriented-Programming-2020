#include <iostream>
using namespace std;
#include <string>

extern float add_op(float left, float right);
extern float subtract_op(float left, float right);
extern float multiply_op(float left, float right);
extern float divide_op(float left, float right);
extern float arithmetic_ops(float left, float right, float *op(float,float));

int main(){
	float left = 0;
	float right = 0;
	string op = "\0";
	
	cout << "Enter first number: ";
	cin >> left;
	
	cout << "Enter second number: ";
	cin >> right;
	
	float (*add)(float,float) = &add_op;
	float (*subtract)(float,float) = &subtract_op;
	float (*multiply)(float,float) = &multiply_op;
	float (*divide)(float,float) = &divide_op;	
	
	cout << "+,-,*,/: ";
	cin >> op;
	
	if (op == "+"){
		cout << "The sum is " << (*add)(left,right) << endl;
	}	else if (op == "-"){
		cout << "The difference is "<< (*subtract)(left,right) << endl;
	}	else if (op == "*"){
		cout << "The product is " << (*multiply)(left,right) << endl;
	}	else if (op == "/"){
		cout << "The quotient is " << (*divide)(left,right) << endl;
	}
	
	return 0;
}
