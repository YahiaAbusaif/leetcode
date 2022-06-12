class Solution {
    bool valid[30001];
    string M;
    void solve(int l, int r){
        if( l<0 || r>=M.size() || !(M[l] == '(' &&  M[r] == ')' ) )
            return;
        valid[l]=valid[r]=1;
        l--,r++;
        while(l>=0 && valid[l])
            l--;
        solve(l,r);
    }
public:
    int longestValidParentheses(string s) {
        M=s;
        for(int i=0;i<s.size();i++) {
            solve(i,i+1);
        }
        int ans=0,curr=0;
        for(int i=0;i<s.size();i++) {
            if(valid[i])
                curr++;
            else
            {
                ans=max(ans,curr);
                curr=0;
            }
        }
        ans=max(ans,curr);
        return ans;
    }
};