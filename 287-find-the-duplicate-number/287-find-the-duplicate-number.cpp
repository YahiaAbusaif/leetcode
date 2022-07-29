class Solution {
        
public:
    int findDuplicate(vector<int>& nums) {
        for(int index=0;index<nums.size();index++){
            if(nums[nums[index]&(1<<30)-1] &(1<<30) ){
                for(int index2=0;index2<=index;index2++) {
                    nums[nums[index2]&(1<<30)-1]&=(1<<30)-1;
                }
                return nums[index];
            }
            nums[nums[index]&(1<<30)-1]|=(1<<30);
        }
        return -1;
    }
};