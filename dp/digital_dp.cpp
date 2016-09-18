int dp[len][digit]  
  
int dfs(int len, int dig, bool end_flag){  
    int ILLEGAL, LEGAL;  
    //超过边界值   
    if(len <= 0)  
        return ILLEGAL;  
    //返回已有的DP结果，即记忆化搜索   
    if(!end_flag && dp[len][dig] != -1)  
        return dp[len][dig];      
    //长度只有一位，就不需要枚举下一位了，直接讨论返回即可   
    if(len == 1){  
        return (Q? LEGAL : ILLEGAL);   
    }  
    //开始枚举下一位的数字   
    int end = end_flag? bits[len-2] : 9;   
    int ans = 0;  
    rep(j,0,end + 1){  
        ans += dfs(len-1, j,end_flag && j == end);  
    }  
    if(!end_flag) dp[len][dig] = ans;  
    return ans;  
}  
  
int solve(int n){  
    if(n <= 0)  
        return 0;  
    //求出n的位数，并将其各个位存入数组bits中  
    int l = 0;  
    rep(i,0,21) bits[i] = 0;  
    while(n){  
        bits[l++]= n%10;  
        n /= 10;   
    }  
    //调用dfs求出最后结果，注意到第一个参数l +1是指我们将n前补一个高位0，然后开始查找，这样避免了枚举原来n的最高位  
    return dfs(l+1,0,true);  
} 



