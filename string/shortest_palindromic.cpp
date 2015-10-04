#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if(s=="")
            return "";
        vector<int> dp;
        string extend_s;
        for(int i=0;i<s.size()-1;i++){
            extend_s.push_back(s[i]);
            extend_s.push_back('#');
        }
        extend_s.push_back(s[s.size()-1]);
        dp.resize(extend_s.size(),0);
        
		int max_offset=0;
        int max_i=0;
		int max_len=0;
        for(int i=0;i<dp.size();i++){
            if(dp.size()>100 && i>dp.size()/2+1)
                break;
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
			//cout<<i<<" "<<offset<<endl;
            if(len>max_len){
                max_offset=offset;
                max_i=i;
				max_len=len;
            }
        }
        int k;
        k=dp.size()-1;
        if(dp.size()>100)
            k=dp.size()/2+2;
        for(;k>=0;k--){
            if(dp[k]==k)
                break;
        }
        string result="";
        for(int i=extend_s.size()-1;i>=0;i--){
            if(i%2==1)
                continue;
            if(i<=2*k){
                break;
            }
            result.push_back(extend_s[i]);
        }
        result+=s;
        return result;
    }
};

int main(){
	Solution s;
    string str;
    for(int i=0;i<38859;i++){
        str=str+"a";
    }
    cout<<str.size()<<endl;
    str=s.shortestPalindrome(str);
    cout<<str.size()<<endl;
    //cout <<s.shortestPalindrome(str)<<endl;
}