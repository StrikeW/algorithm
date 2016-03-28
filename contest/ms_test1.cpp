#include <climits>  //INT_MAX  INT_MIN
#include <cstring>

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
using namespace std;


int main(){
	double X,Y,r;
	cin>>X>>Y>>r;

	double max_dis=-1;
	int max_x;
	int max_y;
	for(int a=X-r-1;a<=X+r+1;a++){
		if(r*r-(a-X)*(a-X)<0){
			continue;
		}
		double tmp=sqrt(r*r-(a-X)*(a-X));
		int b[6]={Y+tmp-1,Y+tmp,Y+tmp+1,Y-tmp-1,Y-tmp,Y-tmp+1};
		for(int i=0;i<6;i++){
			double dis=(a-X)*(a-X) + (b[i]-Y)*(b[i]-Y);
			if( dis > r*r || dis<max_dis){
				continue;
			}
			if(dis>max_dis){
				max_dis=dis;
				max_x=a;
				max_y=b[i];
			} else if(dis == max_dis){
				if(a>max_x || (a==max_x && b[i]>max_y)){
					max_x=a;
					max_y=b[i];
				}
			}
		}	
	}
	cout<<max_x<<" "<<max_y<<endl;
}





