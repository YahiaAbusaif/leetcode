class Solution {
    vector<string> res;
    int limit;
    
    void solve(string curr,int sum){
        if(sum < 0)
            return;
        if(curr.size()==limit)
        {
            if(sum==0)
                res.push_back(curr);
            return;
        }
        solve(curr+"(",sum+1);
        solve(curr+")",sum-1);
    }
public:
    vector<string> generateParenthesis(int n) {
        limit=n*2;
        solve("",0);
        return res;
    }
    
};