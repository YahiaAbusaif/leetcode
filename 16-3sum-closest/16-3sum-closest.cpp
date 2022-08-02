class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans=0,different=100000001,end1=nums.size()-2,end2=nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int i=0 ; i<end1 ; i++)
        {
            int j=i+1,k=end2,sum=0;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];   
                if(abs(sum - target) < different){
                    if(sum==target)
                        return sum;
                    different = abs(sum - target);     
                    ans = sum;
                } 
                
                if(sum>target)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};