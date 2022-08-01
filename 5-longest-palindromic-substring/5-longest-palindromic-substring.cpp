class Solution {
    int AsLongAsPossiable(const string &s,int idx)
    {
        int ans=1,l=idx-1,r=idx+1;
        while(l>=0 && r<s.size())
        {
            if(s[l]!=s[r])
                return ans;
            l--,r++,ans+=2;
        }
        return ans;
    }
    int PossiablePair(const string &s,int idx)
    {
        int ans=0,l=idx,r=idx+1;
        while(l>=0 && r<s.size())
        {
            if(s[l]!=s[r])
                return ans;
            l--,r++,ans+=2;
        }
        return ans;
    }
public:
    string longestPalindrome(string s) {
        int ans=1,idx=0;
        for(int i=0;i<s.size();i++)
        {
            int temp = AsLongAsPossiable(s,i);
            if(ans<temp)
                ans=temp,idx=i;
        }
        for(int i=0;i<s.size();i++)
        {
            int temp = PossiablePair(s,i);
            if(ans<temp)
                ans=temp,idx=i;
        }
        return s.substr(idx-(ans-1)/2, ans);
    }
};