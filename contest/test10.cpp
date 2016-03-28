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


struct factor{
	LL value;
	LL n;
};
vector<factor> get_factors(LL input){
	vector<factor> result;
	factor f;
	f.value=2;
	f.n=0;
	while(input>1){
		if(input % f.value ==0){
			f.n++;
			input=input/f.value;
		} else {
			if(f.n>0)
				result.push_back(f);
			f.value++;
			f.n=0;
		}
	}
	if(f.n>0)
		result.push_back(f);
	return result;
}

vector<factor> merge(vector<factor>& v0,vector<factor>& v1){
	vector<factor> result;
	int idx0;
	int idx1;
	while(idx0<v0.size() && idx1<v1.size()){
		if(v0[idx0].value == v1[idx1].value ){
			factor f;
			f.value=v0[idx0].value;
			f.n=min(v0[idx0].n,v1[idx1].n);
			result.push_back(f);
			idx0++;
			idx1++;
			continue;
		}
		if(v0[idx0].value < v1[idx1].value ){
			idx0++;
			continue;
		}
		if(v0[idx0].value > v1[idx1].value ){
			idx1++;
			continue;
		}
	}
	return result;
}

LL count(vector<factor>& v0){
	if(v0.size()==0){
		return 1;
	}
	LL result=1;
	for(int i=0;i<v0.size();i++){
		result=result*(v0[i].n+1);
	}
	return result;
}
int main(){
	LL N,M;
	cin>>N>>M;
	vector<factor> vec_n = get_factors(N);
	vector<factor> vec_m = get_factors(M);

	vector<factor> common=merge(vec_n,vec_m);

	LL A=count(vec_n) * count(vec_m);
	LL B=count(common);
	LL common_div=2;
	while(true){
		if(common_div>B){
			break;
		}
		if(B%common_div == 0 && A%common_div ==0){
			B = B / common_div;
			A = A / common_div;
			continue;
		} else {
			common_div ++;
		}
	}
	cout<<A<<" "<<B<<endl;
}

