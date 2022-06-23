class Solution {
    vector<string> res;
    unordered_set <string> stringSet;
    string ss;
    int resSize;
    
    void solve(string ans, int idx, int curr, int group)
    {
        if(group>4)
            return;
        if(idx >= ss.size())
        {
            if(curr)
                return;
            ans= ans.substr(0, ans.length() - 1);
            if(ans.size()==resSize && stringSet.find(ans) == stringSet.end())
            {
                    res.push_back(ans);
                    stringSet.insert(ans) ;
            }
            return;
        }

        int newCurr = (curr*10) + (ss[idx]-'0');
        if( newCurr == 0)
        {
            solve(ans+"0.",idx+1,0,group+1);
        }
        else if (newCurr >255)
        {
            solve(ans + to_string(curr)+"." ,idx,0,group+1);
        }
        else
        {      
            solve(ans+to_string(newCurr)+"." ,idx+1,0,group+1);
            solve(ans,idx+1,newCurr,group);
        }


    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        ss=s;
        resSize = s.size()+3;
        solve("",0,0,0);
        return res;
    }
};