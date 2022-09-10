class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> exist;
        for(int index=0;index<nums.size();index++)
        {
            exist[nums[index]]=true;
        }
        int ans=0;
        for(int index=0;index<nums.size();index++)
        {
            if(exist[nums[index]]){
                int curr=1, mx=nums[index]+1,mn=nums[index]-1;
                while(exist[mn]){
                    exist[mn]=false;
                    curr++, mn--;
                }
                while(exist[mx]){
                    exist[mx]=false;
                    curr++, mx++;
                }
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};