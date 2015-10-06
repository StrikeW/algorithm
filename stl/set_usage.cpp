#include <iostream>
#include <set>
using namespace std;

void basic(){
	set<int> s;
	s.insert(1);
	s.insert(5);
	s.insert(4);
	s.insert(2);
	s.insert(3);
	set<int>::iterator iter;
	for(iter=s.begin();iter!=s.end()iter++){
		cout<<*iter<<endl;
	}
}
int main(){
	basic();
}