#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<int> dp;
        string extend_s;
        for(int i=0;i<s.size()-1;i++){
            extend_s.push_back(s[i]);
            extend_s.push_back('#');
        }
        extend_s.push_back(s[s.size()-1]);
        dp.resize(extend_s.size());
        
		int max_offset=0;
        int max_i=0;
		int max_len=0;
        for(int i=0;i<dp.size();i++){
            dp[i]=1;
            int offset=0;
            if(max_offset!=0 && i<=max_i+max_offset){
				offset=dp[max_i*2-i];
			}
			while(true){
                if(i-offset-1<0 || i+offset+1 >=dp.size())
                    break;
                if(extend_s[i-offset-1] ==extend_s[i+offset+1])
                    offset++;
                else
                    break;
            }
            dp[i]=offset;
			int len=0;
			if(i%2==0)
				len=1+2*(offset/2);
			else 
				len=2*((offset+1)/2);
			cout<<i<<" "<<offset<<endl;
            if(len>max_len){
                max_offset=offset;
                max_i=i;
				max_len=len;
            }
        }
        string result="";
        for(int i=max_i-max_offset;i<=max_i+max_offset;i++){
            if(i%2==1)
                continue;
            result.push_back(extend_s[i]);
        }
        return result;
    }
};

int main(){
	Solution s;
	cout <<s.longestPalindrome("abb")<<endl;
}
