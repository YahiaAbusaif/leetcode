class Solution {
    
    int dp[13][10001];
    vector<int> nums;
    
    int solve(int index, int rest){
        if(index<0 || rest<=0){
            return rest==0 ? 0:1e9;
        }
        if(dp[index][rest]!=-1)
            return dp[index][rest];
        dp[index][rest]= min(solve(index-1,rest),solve(index,rest-nums[index])+1);
        return dp[index][rest];
        
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        nums=coins;
        memset(dp,-1,sizeof(dp));
        int ans=solve(coins.size()-1,amount);
        return ans <1e5 ? ans : -1;
    }
};