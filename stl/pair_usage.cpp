//#include <utility> // include for pair; but it seems ok without it ?
#include <iostream>
using namespace std;

void basic_construct(){
	//default
	//2,0.5
	pair<int,double> pa(2,0.5);
	
	//2,0.5
	pair<int,double> pb(pa);

	//1,1
	pair<int,double> pc=make_pair(pb.first-1,pb.second+0.5);

	cout<<pc.first<<","<<pc.second<<endl;
}
int main(){
	basic_construct();
}