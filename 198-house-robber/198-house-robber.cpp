class Solution {
    int dp[101];
    vector<int> arr;
    
    int MaxSum(int index){
        if(index>=arr.size())
            return 0;
        if(dp[index]!=-1)
            return dp[index];
        dp[index]=max(MaxSum(index+1),MaxSum(index+2)+arr[index]);
        return dp[index];
    }
    
public:
    int rob(vector<int>& nums) {
        arr=nums;
        memset(dp,-1,sizeof(dp));
        return MaxSum(0);
        
    }
};