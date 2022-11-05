class Solution {
public:
    int dp[10001];
    vector<int> arr;

    int solve(int index){
        if(index >=arr.size()-1)
            return 0;
        if(dp[index]!=-1){
            return dp[index];
        }
        dp[index]=1e8;
        for(int iter=arr[index];iter>0;iter--){
            dp[index]=min(dp[index],solve(index+iter)+1);
        }
        return dp[index];
    }
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        arr=nums;
        return solve(0);
    }
};