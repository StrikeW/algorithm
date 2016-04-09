#include <iostream>
#include <algorithm>
#include <vector>

// 几个二分查找的函数
// bool binary_search(vec.begin(), vec.end(), target);
//		true:找到
//		false:没找到

// vector<int>::iterator  lower_bound(vec.begin(), vec.end(), target);
// 存在的话返回第一个
// 不存在的话返回比他大的第一个

// vector<int>::iterator  upper_bound(vec.begin(), vec.end(), target);
// 返回比他大的第一个


using namespace std;

void binary(){
	vector<int> vec;
	for(int i=0;i<1000;i++){
		vec.push_back(2*i);
		vec.push_back(2*i);
		vec.push_back(2*i);
	}
	int target[5]={-5,10,99,1998,2005};
	for(int i=0;i<5;i++){
		vector<int>::iterator iter1=lower_bound(vec.begin(), vec.end(), target[i]);
		vector<int>::iterator iter2=upper_bound(vec.begin(), vec.end(), target[i]);
		if(iter1==iter2){
			cout<<target[i]<<" No found"<<endl;
		} else {
			cout<<target[i]<<" appears "<<iter2-iter1 <<" times"<<endl;
		}
	}
}
int main(){
	binary();
}