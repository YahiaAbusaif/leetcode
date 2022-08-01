class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long ans=1,countZero=0;
        for(int index=0; index<nums.size();index++){
            if(nums[index]!=0)
                ans*=nums[index];
            countZero+=(nums[index]==0);
        }
        vector<int> result(nums.size(),0);
        if(countZero>1)
            return result;
        for(int index=0 ; index<nums.size(); index++){
            if(countZero == 1 )
            {
                if(nums[index]==0)
                    result[index]=ans;
            }
            else
                result[index]=ans/nums[index];
        }
        return result;
    }
};