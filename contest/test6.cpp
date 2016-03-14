#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct poster{
	double X1,Y1,X2,Y2;
	vector<int> child;
	// 2    3
	// 0    1

	bool covered[4];
	poster(){
		covered[0]=false;
		covered[1]=false;
		covered[2]=false;
		covered[3]=false;
	}
	bool alive(){
		for(int i=0;i<4;i++){
			if(!covered[i]){
				return true;
			}
		}
		return false;
	}
	bool point_inside(double x,double y){
		if(x>X1 && x<X2 && y>Y1 && y<Y2){
			return true;
		}
		return false;
	}
};

bool helper(poster& pbefore,  poster& pafter){
	if(pbefore.point_inside(pafter.X1,pafter.Y1))
		return true;
	if(pbefore.point_inside(pafter.X2,pafter.Y1))
		return true;
	if(pbefore.point_inside(pafter.X1,pafter.Y2))
		return true;
	if(pbefore.point_inside(pafter.X2,pafter.Y2))
		return true;
	if(pbefore.point_inside(pafter.X1,(pafter.Y1+pafter.Y2)/2))
		return true;
	if(pbefore.point_inside(pafter.X2,(pafter.Y1+pafter.Y2)/2))
		return true;
	if(pbefore.point_inside((pafter.X1+pafter.X2)/2, pafter.Y1))
		return true;
	if(pbefore.point_inside((pafter.X1+pafter.X2)/2, pafter.Y2))
		return true;
	return false;
}
bool cover(poster& pbefore,  poster& pafter,int after){
	if(pafter.point_inside(pbefore.X1,pbefore.Y1)){
		pbefore.covered[0]=true;
	}
	if(pafter.point_inside(pbefore.X2,pbefore.Y1)){
		pbefore.covered[1]=true;
	}
	if(pafter.point_inside(pbefore.X1,pbefore.Y2)){
		pbefore.covered[2]=true;
	}
	if(pafter.point_inside(pbefore.X2,pbefore.Y2)){
		pbefore.covered[3]=true;
	}
	if(helper(pbefore,pafter) || helper(pafter,pbefore)){
		pbefore.child.push_back(after);
		return true;
	}
	return false;
}

int main(){
	int W,H,N;
	cin >>W>>H>>N;
	vector<poster> vec_poster;
	for(int i=0;i<N;i++){
		poster p;
		cin >>p.X1 >>p.Y1 >>p.X2 >>p.Y2;
		vec_poster.push_back(p);
	}
	for(int i=0;i<vec_poster.size();i++){
		for(int j=i+1;j<vec_poster.size();j++){
			cover(vec_poster[i],vec_poster[j],j);
		}
	}
	vector<bool> tested;
	int Ans=-1;
	int K=-1;

	tested.resize(vec_poster.size(),false);
	for(int i=0;i<vec_poster.size();i++){
		if(tested[i]){
			continue;
		}
		if(!vec_poster[i].alive()){
			continue;
		}
		vector<bool> removed;
		removed.resize(vec_poster.size(),false);
		queue<int> todo_list;
		todo_list.push(i);
		while(todo_list.size()>0){
			int next=todo_list.front();
			todo_list.pop();
			removed[next]=true;
			tested[next]=true;
			for(int j=0;j<vec_poster[next].child.size();j++){
				int c=vec_poster[next].child[j];
				if(!removed[c]){
					todo_list.push(c);
				}
			}
		}
		int count=0;
		for(int k=0;k<removed.size();k++){
			if(removed[k]){
				count++;
			}
		}
		if(count>Ans){
			Ans=count;
			K=i+1;
		}
	}
	cout<<Ans<<" "<<K<<endl;
}