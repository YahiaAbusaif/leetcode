class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3];
        cnt[0]=cnt[1]=cnt[2]=0;
        for( int i = 0 ; i < nums.size();i++)
        {
            cnt[nums[i]]++;
        }
        int start=0;
        for(int i=0 ; i< nums.size();i++){
            while(cnt[start]==0)
                start++;
            nums[i] = start;
            cnt[start]--;
        }
        
    }
};