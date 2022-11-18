class Solution {
    bool dp[10001][201];
    vector<int> arr;
    
    bool solve(int rem,int index){
        if(rem==0)
            return true;
        if(index>=arr.size() || rem<0 || dp[rem][index])
            return false;
        dp[rem][index]=true;
        return solve(rem,index+1)|| solve(rem-arr[index],index+1);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        memset(dp,false, sizeof(dp));
        arr= nums;
        int sum=0;
        for(int index=0;index<nums.size();index++){
            sum+=nums[index];
        }
        if(sum&1){
            return false;
        }
        return solve(sum/2,0);
    }
};