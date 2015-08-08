#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool> > dp;
		vector<char > pp;
		vector<bool > pstar;
		for(int i=0;i<p.size();i++){
			// error
			if(p[i]=='*')
				return false;
			pp.push_back(p[i]);
			if(i+1<p.size() && p[i+1]=='*'){
				i++;
				pstar.push_back(true);
			} else {
				pstar.push_back(false);
			}
		}
		dp.resize(s.size()+1);
		for(int i=0;i<dp.size();i++){
			dp[i].resize(pp.size()+1);
			dp[i][0]=false;
		}
		dp[0][0]=true;
		for(int k=0;k<pp.size();k++){
			if(pstar[k]){
				dp[0][k+1]=true;
			} else {
				break;
			}
		}
		for(int k=0;k<pp.size();k++){
			if(pstar[k]){
				for(int i=0;i<dp.size();i++){
					if(dp[i][k]==true){
						dp[i][k+1]=true;
						int tmp=i+1;
						while(tmp<dp.size() && (s[tmp-1]==pp[k] || pp[k]=='.')) {
							dp[tmp][k+1]=true;
							tmp++;
						}
					}
				}				
			} else {//pstar[k] ==false
				for(int i=0;i<dp.size();i++){
					if(dp[i][k]==true){
						if(i+1<dp.size() && (s[i]==pp[k] || pp[k]=='.'))
							dp[i+1][k+1]=true;
					}
				}
			}
		}
		return dp[dp.size()-1][dp[0].size()-1];
	}
};
/*
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
int main(){
	Solution s;
	cout<<s.isMatch("aa","a")<<endl;
	cout<<s.isMatch("aa","aa")<<endl;
	cout<<s.isMatch("aaa","aa")<<endl;
	cout<<s.isMatch("aa","a*")<<endl;
	cout<<s.isMatch("aa",".*")<<endl;
	cout<<s.isMatch("ab",".*")<<endl;
	cout<<s.isMatch("aab","c*a*b")<<endl;

}

