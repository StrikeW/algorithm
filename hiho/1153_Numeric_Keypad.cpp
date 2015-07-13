#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool found;
int size[10]={1,10,7,3,7,5,2,4,3,1};
int p[10][10]={
	{0},
	{9,8,7,6,5,4,3,2,1,0},
	{9,8,6,5,3,2,0},
	{9,6,3},
	{9,8,7,6,5,4,0},
	{9,8,6,5,0},
	{9,6},
	{9,8,7,0},
	{9,8,0},
	{9}
};
int input[505];
int output[505];
int length;
void dfs(int prev,int index,bool choose_largest){
	if(index>=length){
		found=true;
		return;
	}
	if(found)
		return ;
	if(choose_largest){
		int largest=p[prev][0];
		output[index]=largest;
		dfs(largest,index+1,true);
		return ;
	}
	for(int i=0;i<size[prev];i++){
		int current=p[prev][i];
		if(found)
			return ;
		if(current <= input[index]){
			output[index]=current;
			//cout<<prev<<"->"<<current<<endl;
			if(current == input[index])
				dfs(current,index+1,false);
			else
				dfs(current,index+1,true);
		}
	}
}
int main(){
	int T;
	cin>>T;
	while(T>0){
		T--;
		found=false;
		string str;
		cin>>str;
		length=str.size();
		for(int i=0;i<length;i++){
			input[i]=str[i]-'0';
			output[i]=0;
		}
		dfs(1,0,false);
		for(int i=0;i<length;i++){
			printf("%d",output[i]);
		}
		printf("\n");
	}
	// for(int i=0;i<10;i++){
	// 	for(int j=0;j<size[i];j++)
	// 		cout<<p[i][j]<<" ";
	// 	cout<<endl;
	// }
}