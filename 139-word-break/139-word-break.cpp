class Solution {
    unordered_map<string,bool> dict;
    string target;
    int mx=0;
    bool dp[301][21];
    
    bool solve(int index, int length){
        if(index==target.size() && length<=1)
            return true;
        if(index+length>target.size() || length>mx){
            return false;
        }
        if(dp[index][length])
            return false;
        dp[index][length]=true;
        bool temp = solve(index,length+1);
        if(dict.find(target.substr(index, length)) != dict.end()){
            temp|= solve(index+length,1);
        }
        return temp;
        
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int index=0; index< wordDict.size(); index++){
            dict[wordDict[index]]=true;
            mx = (mx<wordDict[index].size())?wordDict[index].size():mx;
        }
        target=s;
        return solve(0,1);
        
    }
};