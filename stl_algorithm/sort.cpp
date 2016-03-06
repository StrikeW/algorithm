#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//sort(v.begin(),v.end());
//sort(v.begin(),v.end(),cmp);

bool cmp(int a,int b){
    return a*a < b*b;
}
void sort(){
	int a[] = {3,-2,5,-4,1};
	int a_len=sizeof(a)/sizeof(a[0]);
    vector<int> v2(a,a+a_len);
    sort(v2.begin(),v2.end());
    for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
    cout<<endl;

	//sort based on square value;
	sort(v2.begin(),v2.end(),cmp);
    for(int i=0;i<v2.size();i++)
		cout<<v2[i]<<" ";
    cout<<endl;
}

//sort user-defined objects
struct mystruct {
    int a;
    int b;
    mystruct(int _a,int _b):a(_a),b(_b){};
    bool operator < (const mystruct& other) const {
        return (a < other.a);
    }
};
bool mystruct_cmp(mystruct& s0,mystruct& s1){
    return s0.b < s1.b;
}
void mystruct_sort(){
    vector<mystruct> v;
    v.push_back(mystruct(2,5));
    v.push_back(mystruct(1,6));
    v.push_back(mystruct(3,4));

    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
		cout<<v[i].a<<" "<<v[i].b<<endl;
    }

    sort(v.begin(),v.end(),mystruct_cmp);
    for(int i=0;i<v.size();i++){
		cout<<v[i].a<<" "<<v[i].b<<endl;
    }
}


int main(){
    //sort();
    mystruct_sort();
}
