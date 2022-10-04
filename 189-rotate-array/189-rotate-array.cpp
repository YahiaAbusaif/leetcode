class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int step= k%nums.size();
        if(k==0 || step==0)
            return;
        vector<int> temp(step);
        int jumb = nums.size()-step;
        for(int index =0; index<step ; index++){
            temp[index]= nums[index+jumb];
        }
        for(int index =nums.size()-1 ; index>=step;index--){
            nums[index] = nums[index-step];
        }
        for(int index =0; index<step;index++){
            nums[index]= temp[index];
        }
    
    }
};