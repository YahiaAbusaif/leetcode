class Solution {
    vector<vector<int> > procNums;
    int ans;
    void getRealNumber(vector<int>& nums){
        int vectorIndex=0, index=0;
        while(index<nums.size() && nums[index]==0)
            index++;
        ans = index == 0 ? -11:0;
        vector<int> Array;
        procNums.push_back(Array);
        for(;index<nums.size();index++)
        {
            ans=max(ans,nums[index]);
            if(nums[index] == 1)
                continue;
            else if(nums[index] == -1){
                if(procNums[vectorIndex].size()>1 && procNums[vectorIndex].back()==-1 && procNums[vectorIndex].end()[-2]==-1){
                    procNums[vectorIndex].pop_back();
                    ans= max(ans,1);
                }
                else
                    procNums[vectorIndex].push_back(-1);
            }
            else if(nums[index] == 0){
                if(procNums[vectorIndex].size()>1)
                {
                    vectorIndex++;
                    vector<int> newArray;
                    procNums.push_back(newArray);
                }
                else
                    procNums[vectorIndex].clear();
                
                while(index+1<nums.size() && nums[index+1]==0)
                    index++;
            }
            else
                procNums[vectorIndex].push_back(nums[index]);
        }
    }
    
    void getMaxProd(int index){
        for(int i =0 ;i<procNums[index].size();i++){
            int prod=1;
            for(int j=i;j<procNums[index].size();j++){
                prod*=procNums[index][j];
                ans=max(ans,prod);
            }
        }
    }
public:
    int maxProduct(vector<int>& nums) {
        getRealNumber(nums);
        for(int index =0; index<procNums.size();index++){
            getMaxProd(index);
        }
        
        return ans;
        
        
    }
};