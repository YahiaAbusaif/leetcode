class Solution {
    
    int isSolution(int num, int val,vector<int>& nums){
        int n = lower_bound (nums.begin(), nums.end(), val) - nums.begin();
        int m = upper_bound (nums.begin(), nums.end(), val) - nums.begin();
        if( num >= n && num <= m)
                return 0;
        if(n>num)
            return 1;
        return 2;
        
    }
    double findIdx(int target ,vector<int>& nums1, vector<int>& nums2) {
        int l=0,r=nums1.size()-1, mid,sol;
        while(r>l+1)
        {
            mid=(r+l)>>1;
            sol=isSolution(target-mid,nums1[mid],nums2);
            if(sol == 0)
                return nums1[mid];
            if(sol==1)
                r=mid-1;
            else
                l= mid;
        }
        for(;l<=r;l++)
        {
            if(isSolution(target-l,nums1[l],nums2) == 0)
                return nums1[l];
        }
        l=0,r=nums2.size()-1;
        while(r>l+1)
        {
            mid=(r+l)>>1;
            sol=isSolution(target-mid,nums2[mid],nums1);
            if(sol == 0)
                return nums2[mid];
            if(sol==1)
                r=mid-1;
            else
                l= mid;
        }
        for(;l<=r;l++)
        {
            if(isSolution(target-l,nums2[l],nums1) == 0)
                return nums2[l];
        }
        return 0;
    }
    
    
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ans,sz=nums1.size()+nums2.size(),mymid=sz>>1;
        double res= findIdx(mymid,nums1,nums2);

        if(sz%2==0)
        {
            res = (res+findIdx(mymid-1,nums1,nums2))/2;
        }
        return res;
    }
};