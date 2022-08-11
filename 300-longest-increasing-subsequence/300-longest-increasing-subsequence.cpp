class Solution {
    int dp[2500][2500];
    vector<int> numbers;
    int solve(int currentIndex,int lastIndex){
        if(currentIndex >= numbers.size()){
            return 0;
        }
        int & result = dp[currentIndex][lastIndex];
        if(result != -1)
            return result;
        result = solve(currentIndex+1,lastIndex==currentIndex? currentIndex+1:lastIndex);
        if(numbers[currentIndex] > numbers[lastIndex] || lastIndex==currentIndex)
            result=max(result,solve(currentIndex+1,currentIndex)+1);
        return result;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        numbers = nums;
        return solve(0,0);
    }
};