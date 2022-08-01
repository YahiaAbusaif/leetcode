class Solution {
    vector<vector<int>> solve2(const vector<int>& nums,long long sum,int l, int r)
    {
        vector<vector<int>> res;
        int i=l+1,j=r-1;
        while(i<j)
        {
            if(sum-((long long)nums[i]+(long long)nums[j])==0)
            {
                vector<int> temp(4);
                temp[0]=nums[l],temp[1]=nums[i],temp[2]=nums[j],temp[3]=nums[r];
                res.push_back(temp);
                i++;
                while(i<j && nums[i]==nums[i-1])
                    i++;
            }
            else if(sum-((long long)nums[i]+(long long)nums[j])<0)
                j--;
            else
                i++;
        }
        
        return res;
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            cout<<nums[i]<<" ";
        cout<<endl;
        int end=nums.size()-3,left=nums.size()-1;
        vector< vector<int> > res;
        for(int i=0;i<end;i++)
        {
            int jstop=i+3;
            for(int j=left;j>=jstop;j--)
            {
                long long sum=target;
                sum-=(nums[i]+nums[j]);
                vector< vector<int> > temp=solve2(nums,sum,i,j);
                res.insert(res.end(), temp.begin(), temp.end());
                while(j>=jstop && nums[j]==nums[j-1])
                    j--;
            }
            while(i<end&&nums[i]==nums[i+1])
                i++;
        }
        return res;
    }
};