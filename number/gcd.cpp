#include <iostream>
using namespace std;

int get_gcd(int a,int b){
	if(a<b){
		swap(a,b);
	}
	if(a%b==0){
		return b;
	}
	return get_gcd(a-b,b);
}

int main(){
	cout<<get_gcd(84,60)<<endl;
}