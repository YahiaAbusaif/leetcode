class Solution {
    int bitn(int i){
        int ans=0;
        while(i)
        {
            ans+=(i&1);
            i=i>>1;
        }
        return ans;
    }
public:
    vector<int> countBits(int n) {
        n++;
        vector<int> res(n);
        for(int i=0;i<n;i++)
        {
            res[i]=bitn(i);
        }
        return res;
    }
};