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
    int lengthOfLongestSubstring(string s) {
        if(s.size()<=1)
            return s.size();
        vector<int> pos_table(256,-1);
        int max=1;
        int curr_len=1;
        pos_table[s[0]]=0;
        for(int i=1;i<s.size();i++){
            if(pos_table[s[i]]<i-curr_len){
                curr_len++;
            } else {
                curr_len=i-pos_table[s[i]];
            }
            if(curr_len>max)
                max=curr_len;
            pos_table[s[i]]=i;
        }
        return max;
    }
};


int main(){
    int arr[]={10,5,13,4,8,4,5,11,14,9,16,10,20,8};
    vector<int> v(arr,arr+sizeof(arr)/sizeof(arr[0]));
    
    string s1="abcabcbb";
    string s2="bbbbb";
    Solution s;
    cout<<s.lengthOfLongestSubstring(s1)<<endl;
    cout<<s.lengthOfLongestSubstring(s2)<<endl;
}
