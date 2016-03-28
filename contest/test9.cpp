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


int main(){
	int N;
	cin>>N;
	vector<int> vec;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		vec.push_back(tmp);
	}
	while(vec.size()>1 && vec[vec.size()-1] >vec[vec.size()-2]){
		vec.pop_back();
	}
	if(vec.size()>1 ){
		vec.pop_back();
	}
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}