#include <iostream>
using namespace std;

int main(){
	long long  n=9;
	double d=reinterpret_cast<double& > (n);
	double d2=static_cast<double > (n);

	double d3=*((double* ) (&n));

	cout<<d<<endl;
	cout<<d2<<endl;
	cout<<d3<<endl;
}