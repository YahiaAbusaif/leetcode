class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, ans=0,rest=0;
        unordered_map<int,int> count; 
        for(int index=0;index<nums.size();index++){
            sum+=nums[index];
            count[sum]+=1;
        }
        ans=count[k];
        sum=0;
        
        for(int index=1;index<nums.size();index++){
            sum+=nums[index-1];
            rest=k+sum;
            count[sum]--;
            ans+=count[rest];
        }
        
        return ans;
        
    }
};