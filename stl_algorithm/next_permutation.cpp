#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//next_permutation(v.begin(),v.end())
//prev_permutation -> reverse version of next_permutation

int main(){
    int a[] = {1,1,2,3,3};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v2(a,a+a_len);
    do{
        for(int i=0;i<v2.size();i++)
    		cout<<v2[i]<<" ";
        cout<<endl;
    } while(next_permutation(v2.begin(),v2.end()));
}
