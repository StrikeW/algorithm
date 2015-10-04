#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
//compression+BFS
int vec_to_int(vector<int>& vec){
	//vec[i] means the position of i'th smallest element, [0-6]
	int result=0;
	for(int i=vec.size()-1;i>=0;i--){
		result=result<<3;
		result|=(vec[i]+1);
	}
	return result;
}
vector<int> int_to_vec(int integer){
	vector<int> result;
	while(integer!=0){
		result.push_back((integer&7)-1);
		integer=integer>>3;
	}
	return result;
}
vector<int> vec_to_minvec(vector<int>& vec){
	//minvec[i] means the smallest number at pos i;
	vector<int> minvec;
	minvec.resize(vec.size(),100);
	for(int i=0;i<vec.size();i++){
		minvec[vec[i]]=min(minvec[vec[i]],i);
	}
	return minvec;
}
struct point{
	int level;
	int integer;
	point(int l,int i){
		level=l;
		integer=i;
	}
};
void BFS(vector<int> root,unordered_map<int,int>& level_map){
	int integer=vec_to_int(root);
	queue<point> point_queue;
	point_queue.push(point(0,integer));
	level_map[integer]=0;
	while(point_queue.size()>0){
		point p=point_queue.front();
		point_queue.pop();
		vector<int> p_vec=int_to_vec(p.integer);
		vector<int> minvec=vec_to_minvec(p_vec);
		for(int i=0;i<p_vec.size();i++){
			if(p_vec[i]+1<p_vec.size() && minvec[p_vec[i]]==i &&  minvec[p_vec[i]+1] > i ){
				// a valid move
				p_vec[i]++;
				int next_integer=vec_to_int(p_vec);
				if(level_map.find(next_integer)==level_map.end()){
					level_map[next_integer]=p.level+1;
					point_queue.push(point(p.level+1,next_integer));
				}
				p_vec[i]--;
			} 
			if(p_vec[i]-1>=0 && minvec[p_vec[i]]==i && minvec[p_vec[i]-1] > i){
				// a valid move
				p_vec[i]--;
				int next_integer=vec_to_int(p_vec);
				if(level_map.find(next_integer)==level_map.end()){
					level_map[next_integer]=p.level+1;
					point_queue.push(point(p.level+1,next_integer));
				}
				p_vec[i]++;
			} 
		}
	}
}
int main(){
	vector<int> root;
	unordered_map<int,int> level_map;
	for(int i=0;i<7;i++){
		root.push_back(i);
		BFS(root,level_map);
	}
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		vector<int> target;
		int n;
		cin>>n;
		for(int j=0;j<n;j++){
			int tmp;
			cin>>tmp;
			target.push_back(tmp);
		}
		vector<int> converted_vec;
		for(int j=0;j<target.size();j++){
			int index=0;
			for(int k=0;k<target.size();k++){
				if(target[k]<target[index]){
					index=k;
				}
			}
			converted_vec.push_back(index);
			target[index]=10000;
		}
		int integer=vec_to_int(converted_vec);
		if(level_map.find(integer)==level_map.end()){
			cout<<-1<<endl;
		} else {
			cout<<level_map[integer]<<endl;
		}
	}
}