#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <cstring> //memset
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define INF 0x3f3f3f3f
#define CLR(a, b) memset(a, b, sizeof(a))


typedef pair<int,int> point;

int main(){
	int T;
	cin>>T;
	while(T>0){
		T--;
		vector<point > point_vec;
		for(int i=0;i<4;i++){
			point p1;
			point p2;
			cin>>p1.first;
			cin>>p1.second;
			cin>>p2.first;
			cin>>p2.second;
			point_vec.push_back(p1);
			point_vec.push_back(p2);
		}
		vector<point > rectangle;
		rectangle.push_back(point_vec[0]);
		rectangle.push_back(point_vec[1]);
		for(int i=2;i<8;i++){
			if(point_vec[i]==rectangle[1]){
				int j=i/2*2+(1-i%2);
				rectangle.push_back(point_vec[j]);
				point_vec[i]=point(100001,100001);
				point_vec[j]=point(100001,100001);
				break;
			}
		}
		if(rectangle.size()!=3){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=2;i<8;i++){
			if(point_vec[i]==rectangle[2]){
				int j=i/2*2+(1-i%2);
				rectangle.push_back(point_vec[j]);
				point_vec[i]=point(100001,100001);
				point_vec[j]=point(100001,100001);
				break;
			}
		}
		if(rectangle.size()!=4){
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=2;i<8;i++){
			if(point_vec[i]==rectangle[3]){
				int j=i/2*2+(1-i%2);
				rectangle.push_back(point_vec[j]);
				point_vec[i]=point(100001,100001);
				point_vec[j]=point(100001,100001);
				break;
			}
		}
		if(rectangle.size()!=5 || rectangle[0]!=rectangle[4]){
			cout<<"NO"<<endl;
			continue;
		}
		rectangle.pop_back();

		point p01=point(rectangle[1].first-rectangle[0].first,rectangle[1].second-rectangle[0].second);
		point p32=point(rectangle[2].first-rectangle[3].first,rectangle[2].second-rectangle[3].second);
		if(p01!=p32 || p01==point(0,0)){
			cout<<"NO"<<endl;
			continue;
		}
		point p03=point(rectangle[3].first-rectangle[0].first,rectangle[3].second-rectangle[0].second);
		point p12=point(rectangle[2].first-rectangle[1].first,rectangle[2].second-rectangle[1].second);
		if(p03!=p12 || p03==point(0,0)){
			cout<<"NO"<<endl;
			continue;
		}
		if(p01.first*p03.first + p01.second*p03.second ==0){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}











