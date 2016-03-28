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

bool check(vector<int>& nums,int x,int y,int z){
	vector<int> v1;
	v1.push_back(abs(nums[1]-nums[0]));
	v1.push_back(abs(nums[2]-nums[0]));
	v1.push_back(abs(nums[2]-nums[1]));
	vector<int> v2;
	v2.push_back(x);
	v2.push_back(y);
	v2.push_back(z);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(int i=0;i<3;i++){
		if(v1[i]!=v2[i]){
			return false;
		}
	}
	return true;
}

int main(){
	int x,y,z;
	cin>>x>>y>>z;
	string str;
	cin>>str;

	vector<int> nums;
	nums.resize(3);
	int max_sum=0;
	for(int i=0;i<str.size();i++){
		if(str[i]=='R'){
			nums[0]++;
		}
		if(str[i]=='B'){
			nums[1]++;
		}
		if(str[i]=='Y'){
			nums[2]++;
		}
		int sum= nums[0]+nums[1]+nums[2];
		if(sum>max_sum){
			max_sum=sum;
		}
		if(check(nums,x,y,z)){
			nums[0]=0;
			nums[1]=0;
			nums[2]=0;
		}
	}
	cout<<max_sum<<endl;
}







