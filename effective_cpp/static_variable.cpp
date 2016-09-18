#include <iostream>
using namespace std;

int get_static(int i){

	static int r1=i;
	*(&r1+2)=0;
	return r1;
}

void try_const(){
	const int constant = 21;
	const int* const_p = &constant;
	int* modifier = const_cast<int*>(const_p);
	*modifier = 7;

	cout << "constant: "<< constant <<endl;//21
	cout << "const_p: "<< *const_p <<endl;//7
	cout << "modifier: "<< *modifier <<endl;//7

	cout << "constant: "<< &constant <<endl;//0x22fef4
	cout << "const_p: "<< const_p <<endl;//0x22fef4
	cout << "modifier: "<< modifier <<endl;//0x22fef4
}
int main(){
//	cout<<get_static(1)<<endl;
//	cout<<get_static(2)<<endl;
	try_const();
}