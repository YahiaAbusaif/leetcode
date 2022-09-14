class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mn=1e5,mx=-1e5,index=0, sum=0, range;

        for(;index<nums.size();index++)
        {
            mn=min(mn,nums[index]),mx=max(mx,nums[index]);
        }
        range=mx-mn;
        vector<int> array(range+1,0);
        index=0;
        for(;index<nums.size();index++)
        {
            array[nums[index]-mn]++;
        }
        
        index=range;
        for(;index>=0;index--){
            sum+=array[index];
            if(sum>=k)
                return index+mn;
        }
        return index+mn;
    }
};