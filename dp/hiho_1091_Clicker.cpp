#include <iostream>
#include <vector>
using namespace std;

int knapsack(int N,int M,vector<int>& weight, vector<int>& value){
	vector<int> f;
	f.resize(M);
	int max_value=0;
	for(int i=0;i<N;i++){
		for(int j=M-1;j>=0;j--){
			int count=1;
			int curr_w=weight[i];
			int total_w=curr_w;
			while(j-total_w>=0){
				f[j]=max(f[j],f[j-total_w]+count*value[i]);
				count++;
				curr_w=curr_w*1.07;
				total_w+=curr_w;
			}
			if(f[j]>max_value){
				max_value=f[j];	
			}
		}
	}
	return max_value;
}

int main(){
	int N,M;
	cin>>N>>M;
	vector<int> weight;
	vector<int> value;
	weight.resize(N);
	value.resize(N);
	for(int i=0;i<N;i++){
		cin>>value[i]>>weight[i];
	}
	cout<<knapsack(N,M,weight,value)<<endl;
}