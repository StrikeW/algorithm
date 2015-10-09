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
	s.erase(6);
	s.erase(3);

	//iterate 
	set<int>::iterator iter;
	for(iter=s.begin();iter!=s.end();iter++){
		cout<<*iter<<endl;
	}
	
	set<int>::reverse_iterator riter;
	for(riter=s.rbegin();riter!=s.rend();riter++){
		cout<<*riter<<endl;
	}

	//find
	iter=s.find(1);
	iter--;
	cout<<*iter<<endl;
}
struct obj{
	int x;
	int y;
	obj(int xx,int yy):x(xx),y(yy){};
    bool operator < (const obj &a) const
    {	
    	if(x!=a.x)
    		return x<a.x;
        return y<a.y;
    }
};
void my_obj_set(){
	set<obj> s;
	s.insert(obj(2,2));
	s.insert(obj(2,1));
	s.insert(obj(3,2));
	for(set<obj>::iterator iter=s.begin();iter!=s.end();iter++){
		cout<<iter->x<<","<<iter->y<<endl;
	}
}

int main(){
	basic();
	//my_obj_set();
}