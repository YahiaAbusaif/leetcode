class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int arr[20001];
        memset(arr,0,sizeof(arr));
        int index=0;
        for(;index<nums.size();index++)
        {
            arr[nums[index]+10000]++;
        }
        index=20000;
        for(;index>=0;index--){
            if(k-arr[index]<=0)
                return index-10000;
            k-=arr[index];
        }
        return index-10000;
    }
};