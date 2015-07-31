class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool> >dp;
        dp.resize(p.size());
        //dp[i][j]
        for(int i=0;i<p.size();i++){
            dp[i].resize(s.size());
        }
        //some corner case
        if(s==""){
            for(int i=0;i<p.size();i++){
                if(p[i]!='*')
                    return false;
            }
            return true;
        }
        if(p==""){
            return false;
        }
        // set first line
        bool empty_str=true;
        
        if(p[0]=='*'){
            for(int i=0;i<s.size();i++)
                dp[0][i]=true;
        } else {
            empty_str=false;
            if(p[0]=='?'||p[0]==s[0]){
                dp[0][0]=true;
            }    
        }
        for(int i=1;i<p.size();i++){
            if(p[i]=='*'){
                int j=0;
                while(j<s.size()){
                    if(dp[i-1][j]==true)
                        break;
                    j++;
                }
                for(;j<s.size();j++){
                    dp[i][j]=true;
                }
            } else if(p[i]=='?')  {
               if(empty_str){
                   dp[i][0]=true;
               }
               empty_str=false;
               for(int j=0;j<s.size()-1;j++){
                    if(dp[i-1][j]==true)
                        dp[i][j+1]=true;
               }
            } else {
                if(empty_str && p[i]==s[0]){
                   dp[i][0]=true;
                }
                empty_str=false;
                for(int j=0;j<s.size()-1;j++){
                    if(dp[i-1][j]==true && p[i]==s[j+1])
                        dp[i][j+1]=true;
               }
            }
        }
        return dp[p.size()-1][s.size()-1];
    }
};
