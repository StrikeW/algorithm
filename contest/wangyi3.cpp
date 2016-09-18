#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <cstring> //memset
#include <string> //memset
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

bool check_helper(int N,int clear_point,vector<int>& input){
    set<int> exist;
    for(int i=0;i<input.size();i++){
        if(i%N==clear_point){
            exist.clear();
        }
        if(exist.find(input[i])!=exist.end()){
            return false;
        }
        exist.insert(input[i]);
    }
    return true;
}
bool check(int N,vector<int>& input){
    for(int i=0;i<N;i++){
        if(check_helper(N,i,input)){
            return true;
        }
    }
    return false;
}
int main(){
    int S;
    cin>>S;
    for(int s=0;s<S;s++){
        int N,L;
        cin>>N>>L;
        vector<int> input;
        for(int i=0;i<L;i++){
            int tmp;
            cin>>tmp;
            input.push_back(tmp);
        }
        if(check(N,input)){
            cout<<"CAN'T DECIDE"<<endl;
        } else {
            cout<<"B"<<endl;
        }
    }
}
