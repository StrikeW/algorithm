#include <iostream>
#include <vector>

using namespace std;
#define LL long long
#define ULL unsigned long long

int main(){
	int P,Q;
	cin>>P>>Q;
	vector<int> vp;
	vector<int> vq;
	for(int i=1;i<=P;i++){
		if(P%i==0){
			vp.push_back(i);
		}
	}
	for(int i=1;i<=Q;i++){
		if(Q%i==0){
			vq.push_back(i);
		}
	}
	for(int i=0;i<vp.size();i++){
		for(int j=0;j<vq.size();j++){
			printf("%d %d\n",vp[i],vq[j]);
		}	
	}
}


