#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<char> > cafeteria;
	vector<vector<int> > distance;
	cafeteria.resize(N);
	distance.resize(N);
	queue<pair<int,int> > visit_queue;
	for(int i=0;i<N;i++){
		cafeteria[i].resize(M);
		distance[i].resize(M);
		for(int j=0;j<M;j++){
			char c;
			cin>>c;
			cafeteria[i][j]=c;
			distance[i][j]=INT_MAX;
			if(c=='H'){
				visit_queue.push(pair<int,int>(i,j));
				distance[i][j]=0;
			}
		}
	}
	while(visit_queue.size()>0){
		pair<int,int> p=visit_queue.front();
		visit_queue.pop();
		int direct_i[4]={1,-1,0,0};
		int direct_j[4]={0,0,1,-1};
		if(cafeteria[p.first][p.second]=='S')
			continue;
		for(int k=0;k<4;k++){
			int i=p.first+direct_i[k];
			int j=p.second+direct_j[k];
			if(i>=N || i<0 || j>=M || j<0)
				continue;
			if(cafeteria[i][j]=='P' || cafeteria[i][j]=='#')
				continue;
			if(distance[i][j]==INT_MAX){
				distance[i][j]=distance[p.first][p.second]+1;
				visit_queue.push(pair<int,int>(i,j));

			}
		}
	}
	int minimal=INT_MAX;
	for(int i=0;i<N-1;i++){
		for(int j=0;j<M;j++){
			if(cafeteria[i][j]=='S' && cafeteria[i+1][j]=='S'){
				if(distance[i][j]==INT_MAX || distance[i+1][j]==INT_MAX)
					continue;
				int new_dis=distance[i][j]+distance[i+1][j];
				if(new_dis<minimal)
					minimal=new_dis;
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M-1;j++){
			if(cafeteria[i][j]=='S' && cafeteria[i][j+1]=='S'){
				if(distance[i][j]==INT_MAX || distance[i][j+1]==INT_MAX)
					continue;
				int new_dis=distance[i][j]+distance[i][j+1];
				if(new_dis<minimal)
					minimal=new_dis;
			}
		}
	}
	if(minimal==INT_MAX){
		cout<<"Hi and Ho will not have lunch."<<endl;
	} else {
		cout<<minimal<<endl;
	}

}