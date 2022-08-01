class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        bool count=false;
        int needskip=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]==0)
                count=true;
            if(count)
            {
                needskip++;
                if(nums[i]>=needskip)
                {
                    needskip=0;
                    count=false;
                }
            }
        }
        return !count;
    }
};