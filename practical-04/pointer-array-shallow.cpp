#include <iostream>
using namespace std;

int main()
{
	int *ptr= NULL;
	int a[10]={1,2,3,4,5,6,7,8,9,10};	// declaring pointer and array on same line WeirdChamp
	int *b = new int[10];
	
	/* address of a[0] is assigned to ptr */
	ptr = &a[0];
	
	// I want to copy the values in a into b; since i've declared b	// You're not copying a into b, just address LULW
	// as a dynamically allocated array,
	// I can now do pointer magic!!	// magic isn't real
	b = ptr;	// b is now the address of the first value of a
	
	cout << "Value of first element in b " << b[0] << endl;
	cout << "Value of second element in b " << b[1] << endl;
	
	a[1] = 42; // because b is not a copy of a, b will still point to &a[0], so b[1] will reflect changes to a[1]
	cout << "Value of second element in b " << b[1] << endl;
	
	return 0;
}
