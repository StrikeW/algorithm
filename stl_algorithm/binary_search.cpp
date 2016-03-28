#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void lower(){
	vector<int> vec;
	for(int i=0;i<100000;i++){
		vec.push_back(i);
		vec.push_back(i);
		vec.push_back(i);
	}
	vector<int>::iterator iter; 
	iter=lower_bound(vec.begin(), vec.end(), 12345);
	cout<<(iter-vec.begin())<<endl;
}
int main(){
	lower();
}