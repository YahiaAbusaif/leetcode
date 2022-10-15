class Solution {
    
    int countAboveN(unordered_map<int,int>& cnt, int N){
        int ans=0;
        for (auto x : cnt){
            if(x.second >= N)
                ans++;
        }            
        return ans;
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        for(int index=0;index<nums.size();index++){
            if(cnt.find(nums[index])!= cnt.end()){
                cnt[nums[index]]++;
            }
            else{
                cnt[nums[index]]= 1;
            }
        }
        if(nums.size()==cnt.size())
            return nums;
        
        int l=1,r=100001,mid,ans;
        while(l+1<r){
            mid = (l+r)/2;
            ans= countAboveN(cnt,mid);
            if(ans==k){
                break;
            }
            else if(ans>k)
                l=mid+1;
            else
                r=mid-1;
        }
        while(ans<k){
            ans=countAboveN(cnt,--mid);
        }        
        while(ans>k){
            ans=countAboveN(cnt,mid++);
        }
        
        vector<int> res;
        for (auto x : cnt){
            if(x.second>=mid)
                res.push_back(x.first);
        }

        return res;
    }
};