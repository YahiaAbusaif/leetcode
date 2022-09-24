class Solution {
    int dp[101][101];
    int x,y;
    
    int solve(int currx, int curry){
        if(currx>=x||curry>=y)
            return 0;
        if(dp[currx][curry]!= -1)
            return dp[currx][curry];
        dp[currx][curry]= solve(currx+1,curry)+solve(currx,curry+1);
        return dp[currx][curry];
    }
public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        x=m,y=n;
        dp[m-1][n-1]=1;
        return solve(0,0);
    }
};