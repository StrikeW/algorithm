#include <iostream>
#include <vector>
using namespace std;

int knapsack_save_space(int N,int M,vector<int>& weight, vector<int>& value){
	//weight and value size == M+1, first item is used for padding
	vector<int> f;
	f.resize(M+1);
	for(int i=1;i<=N;i++){
		for(int j=M;j>=1;j--){
			int times=1;
			while(j>=times*weight[i]){
				f[j]=max(f[j],f[j-times*weight[i]]+times*value[i]);
				times++;
			}
		}
	}
	int max_value=0;
	for(int i=1;i<=M;i++){
		if(f[i]>max_value)
			max_value=f[i];
	}
	return max_value;
}
int knapsack_opt(int N,int M,vector<int>& weight, vector<int>& value){
	//weight and value size == M+1, first item is used for padding
	vector<int> f;
	f.resize(M+1);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			if(j<weight[i]){

			} else {
				f[j]=max(f[j],f[j-weight[i]]+value[i]);
			}
		}
	}
	int max_value=0;
	for(int i=1;i<=M;i++){
		if(f[i]>max_value)
			max_value=f[i];
	}
	return max_value;
}
int main(){
	int N,M;
	cin >>N>>M;
	vector<int> weight;
	vector<int> value;
	weight.push_back(0);
	value.push_back(0);
	int count=0;
	while(count<N){
		count++;
		int A,B;
		cin>>A>>B;
		weight.push_back(A);
		value.push_back(B);
	}
	cout<<knapsack_opt(N,M,weight,value)<<endl;
}





