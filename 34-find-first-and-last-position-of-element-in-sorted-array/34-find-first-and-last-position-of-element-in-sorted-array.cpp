class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos1= lower_bound(nums.begin(),nums.end(),target)- nums.begin();
        int pos2= upper_bound(nums.begin(),nums.end(),target)- nums.begin();
        if(pos1 + nums.begin() == nums.end() || nums[pos1]!= target)
        {
            vector<int> v(2,-1);
            return v;
        }
        vector<int> v(2,pos1);
        v[1]= pos2+nums.begin() ==nums.end()? nums.size()-1: pos2-1;
        return v;
    }
};