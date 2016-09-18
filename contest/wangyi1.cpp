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

void reverse(int k,int idx,string& str){
    for(int i=idx;i<idx+k;i++){
        if(str[i]=='0'){
            str[i]='1';
        } else {
            str[i]='0';
        }
    }
}
int get_count(string& str){
    int max_count=0;
    int current=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='0'){
            current++;
        } else {
            current=0;
        }
        if(current>max_count){
            max_count=current;
        }
    }
    return max_count;
}
int main(){
    int S;
    cin>>S;
    for(int i=0;i<S;i++){
        int k;
        string str;
        cin>>k>>str;
        int max_size=1;
        /// 01010
        for(int j=0;j<str.size()-k+1;j++){
            reverse(k,j,str);
            int tmp=get_count(str);
            reverse(k,j,str);
            if(tmp>max_size){
                max_size=tmp;
            }

        }
        cout<<max_size<<endl;
    }

}
