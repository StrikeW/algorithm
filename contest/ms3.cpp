#include <climits>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#define CLR(a, b) memset(a, b, sizeof(a))
#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
using namespace std;
int reachable[102][102][102];
// 0 init state
// 1 reachable
// 2 non-empty 
struct point{
	int x;
	int y;
	int z;
	point(int a,int b,int c){
		x=a;
		y=b;
		z=c;
	}
};
void flood(point flood_point){
	queue<point> point_queue;
	point_queue.push(flood_point);
	while(point_queue.size()>0){
		point p=point_queue.front();
		point_queue.pop();
		int dx[6]={1,-1,0,0,0,0};
		int dy[6]={0,0,1,-1,0,0};
		int dz[6]={0,0,0,0,1,-1};
		reachable[p.x][p.y][p.z]=1;
		for(int i=0;i<6;i++){
			if(p.x+dx[i]<0 || p.x+dx[i]>101){
				continue;
			}
			if(p.y+dy[i]<0 || p.y+dy[i]>101){
				continue;
			}
			if(p.z+dz[i]<0 || p.z+dz[i]>101){
				continue;
			}
			int state=reachable[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]];
			if(state==0){
				reachable[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]]=1;
				point_queue.push(point(p.x+dx[i],p.y+dy[i],p.z+dz[i]));
			}
		}
	}
}
bool can_put(point p){
	int dx[6]={1,-1,0,0,0,0};
	int dy[6]={0,0,1,-1,0,0};
	int dz[6]={0,0,0,0,1,-1};
	if(p.z==1){
		return true;
	}
	for(int i=0;i<6;i++){
		int state=reachable[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]];
		if(state==2){
			return true;
		}
	}
	return false;
}
bool near_empty(point p){
	int dx[6]={1,-1,0,0,0,0};
	int dy[6]={0,0,1,-1,0,0};
	int dz[6]={0,0,0,0,1,-1};
	for(int i=0;i<6;i++){
		int state=reachable[p.x+dx[i]][p.y+dy[i]][p.z+dz[i]];
		if(state==1){
			return true;
		}
	}
	return false;
}
int main(){
	//cin.sync_with_stdio(false);
	int T;
	cin>>T;
	for(int t=0;t<T;t++){
		int N;
		cin>>N;
		CLR(reachable,0);
		vector<point> point_vec;
		bool valid=true;
		
		for(int i=0;i<N;i++){
			int x,y,z;
			cin>>x>>y>>z;
			point_vec.push_back(point(x,y,z));
			if(!(can_put(point(x,y,z)))){
				valid=false;
			}
			reachable[x][y][z]=2;
		}
		if(!valid){
			cout<<"No"<<endl;
			continue;
		}
		for(int x=1;x<=100;x++){
			for( int y =1 ; y<=100;y++){
				reachable[x][y][0]=2;
			}
		}
		flood(point(0,0,0));

		for(int i=point_vec.size()-1;i>=0;i--){
			if(near_empty(point_vec[i])){
				reachable[point_vec[i].x][point_vec[i].y][point_vec[i].z]=0;
				flood(point_vec[i]);
			} else {
				valid=false;
				break;
			}
		}
		if(valid){
			cout<<"Yes"<<endl;
		}else {
			cout<<"No"<<endl;
		}
	}
}