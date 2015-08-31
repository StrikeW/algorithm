#include <vector>
#include <string>

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    string countAndSay(int n) {
        string prev="1";
        while(n>1){
            n--;
            string next="";
            int pos=1;
            int count=1;
            while(pos<prev.size()){
                if(prev[pos]==prev[pos-1]){
                    count++;
                } else {
                    next=next+to_string(count);
                    next=next+prev[pos-1];
                    count=1;
                }
                pos++;
            }
            next=next+to_string(count);
            next=next+prev[pos-1];
            prev=next;
        }
        return prev;
    }
};



int main(){
    int arr[]={10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    
    string s1="abcabcbb";
    string s2="bbbbb";
    Solution s;
    cout<<s.countAndSay(6)<<endl;
}
