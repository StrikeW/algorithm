#include <climits>  //INT_MAX  INT_MIN


#include <algorithm>
#include <iostream>
#include <cstring> //memset
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool ispalindrome(string& str){
		int begin=0;
		int end=str.size()-1;
		while(begin<end){
			if(str[begin]!=str[end]){
				return false;
			}
			begin++;
			end--;
		}
		return true;
	}
    vector<vector<int> > palindromePairs(vector<string>& words) {
        vector<vector<int> > result;
        unordered_map<string,int> pos_map;
        for(int i=0;i<words.size();i++){
        	string tmp=words[i];
        	reverse(tmp.begin(),tmp.end());
        	//cout<<"insert "<<tmp<<endl;
            pos_map[tmp]=i;
        }
        for(int i=0;i<words.size();i++){
            //word=a+b
            // case 1
            // a+b+reverse(a), and b is a palindrome
            // case 2
            // reverse(b)+a+b, and a is a palindrome
            for(int sz=0;sz<=words[i].size();sz++){
	            string a=words[i].substr(0,sz);
	            string b=words[i].substr(sz,words[i].size()-sz);
	            if(!ispalindrome(b)){
	            	continue;
	            }
	            if(pos_map.find(a)==pos_map.end()){
	            	continue;
	            }
	           	if(pos_map[a] == i){
	            	continue;
	            }

	            vector<int> r;
	            r.push_back(i);
	            r.push_back(pos_map[a]);
	            result.push_back(r);
	            //cout<<i<<"~"<<pos_map[a]<<endl;
            }
            for(int sz=0;sz<=words[i].size();sz++){
	            string a=words[i].substr(0,sz);
	            string b=words[i].substr(sz,words[i].size()-sz);
	            if(!ispalindrome(a)){
	            	continue;
	            }
	            if(pos_map.find(b)==pos_map.end()){
	            	continue;
	            }
	            if(pos_map[b] == i){
	            	continue;
	            }
	            if(a==""){
	            	continue;
	            }
	            vector<int> r;
	            r.push_back(pos_map[b]);
	            r.push_back(i);
	            result.push_back(r);
	            //cout<<pos_map[b]<<"~"<<i<<endl;
            }
        }
        return result;
    }
};

int main(){
	Solution s;
	vector<string> words;
	words.push_back("abcd");
	words.push_back("dcba");
	words.push_back("lls");
	words.push_back("s");
	words.push_back("sssll");
	s.palindromePairs(words);
}