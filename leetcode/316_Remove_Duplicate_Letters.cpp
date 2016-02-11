#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s==""){
            return "";
        }
        deque<int> int_deque [26];
        int number_of_char=0;
        for(int i=0;i<s.size();i++){
            if(int_deque[s[i]-'a'].size()==0){
                number_of_char++;
            }
            int_deque[s[i]-'a'].push_back(i);
        }
        string ret="";
        while(number_of_char>0){
            int head=0;
            int tail=s.size();
            for(int i=0;i<26;i++){
                if(int_deque[i].size()>0){
                    tail=min(tail,int_deque[i].back());
                }
            }
            for(int i=0;i<26;i++){
                if(int_deque[i].size()>0 && int_deque[i].front()<=tail){
                    head=int_deque[i].front();
                    int_deque[i].clear();
                    ret.push_back('a'+i);
                    break;
                }
            }
            for(int i=0;i<26;i++){
                while(int_deque[i].size()>0 && int_deque[i].front()<head){
                    int_deque[i].pop_front();
                }
            }
            number_of_char--;
        }
        return ret;
    }
};

int main(){
    Solution s;
    cout<<s.removeDuplicateLetters("cbacdcbc")<<endl;
}
