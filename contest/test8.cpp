#include <iostream>
#include <vector>

using namespace std;

struct edge{
	int x;
	int y;
};
int main(){
	int Q;
	cin>>Q;
	for(int q=0;q<Q;q++){
		int N,M;
		cin>>N>>M;
		vector<edge> vec;
		for(int n=0;n<N;n++){
			edge e;
			cin>>e.x>>e.y;
			vec.push_back(e);
		}
		bool can=true;
		for(int i=1;i<vec.size();i++){
			if(vec[i].x==vec[i-1].x && abs(vec[i].y-vec[i-1].y)<M){
				can=false;
				break;
			}
			if(vec[i].y==vec[i-1].y && abs(vec[i].x-vec[i-1].x)<M){
				can=false;
				break;
			}
		}
		if(can){
			cout<<"Yes"<<endl;	
		}else {
			cout<<"No"<<endl;	
		}

	}
}