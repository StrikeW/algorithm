#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int,int> empty_map;
	map<int,pair<int,int> > exist_map;
	int N,M;
	cin>>N>>M;
	empty_map[0]=M;
	for(int i=0;i<N;i++){
		int val;
		cin>>val;
		map<int,int>::iterator empty_iter;
		for(empty_iter=empty_map.begin();empty_iter!=empty_map.end();empty_iter++){
			if(empty_iter->second >=val){
				exist_map[empty_iter->first]=pair<int,int>(i+1,val);
				break;
			}
		}
	}
}