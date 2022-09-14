class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int mn=1e5,mx=-1e5,index, sum=0, range;
        for(index=0;index<nums.size();index++)
            mn=min(mn,nums[index]),mx=max(mx,nums[index]);
        if(k==1)
            return mx;
        if(k==nums.size())
            return mn;
        range=mx-mn;
        vector<int> array(range+1,0);

        for(index=0 ; index<nums.size(); index++)
            array[nums[index]-mn]++;

        for(index=range;index>=0;index--){
            sum+=array[index];
            if(sum>=k)
                return index+mn;
        }
        return mn;
    }
};