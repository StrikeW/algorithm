#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

void insert_and_iterator(){
	unordered_map<int,int> m;
	m[0]=1;
	m[1]=2;
	m[2]=4;
	m[3]=3;
	unordered_map<int,int>::iterator iter;
	for(iter=m.begin();iter!=m.end();iter++){
		cout<<iter->first<<","<<iter->second<<endl;
	}
}
int main(){
	insert_and_iterator();
}

