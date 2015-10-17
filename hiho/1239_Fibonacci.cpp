#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main(){
	int n;
	cin>>n;

	int f1=1;
	int f2=1;
	map<int,int> fibmap;
	vector<int> count_vec;
	count_vec.push_back(0);
	count_vec.push_back(0);
	int index=2;
	while(true){
		int tmp=f1+f2;
		if(tmp>100000)
			break;
		fibmap[tmp]=index;
		count_vec.push_back(0);
		index++;
		f1=f2;
		f2=tmp;
		
	}

	for(int i=0;i<n;i++){
		int input;
		scanf("%d",&input);
		//cin>>input;
		if(input==1){
			count_vec[1]+=count_vec[0];
			count_vec[1]=count_vec[1]%1000000007;
			count_vec[0]++;
		} else {
			if(fibmap.find(input)!=fibmap.end()){
				index=fibmap[input];
				count_vec[index]+=count_vec[index-1];
				count_vec[index]=count_vec[index]%1000000007;
			}
		}
	}
	int result=0;
	for(int i=0;i<count_vec.size();i++){
		result+=count_vec[i];
		result=result%1000000007;
	}
	cout<<result<<endl;
}