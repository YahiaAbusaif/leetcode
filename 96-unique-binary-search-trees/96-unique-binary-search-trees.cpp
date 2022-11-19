class Solution {
    int dp[20];
    
    int solve(int n){
        if(n<=1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        dp[n]=0;
        for(int index=0;index<n;index++){
            dp[n]+=solve(index)*solve(n-(index+1));
        }
        return dp[n];
    }
    
public:
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};