class Solution {
    
    int start=-1;
    int length=1e6;
    
    bool isValid(vector<int> temp, vector<int>res){
        for(int index=0;index<58;index++){
            if(temp[index]<res[index])
                return false;
        }
        return true;
    }
    
    void solve(string s, const vector<int>& target){
        vector<int> res(58,0);
        int left=0,right=0;
        while(right<s.length()){
            if(isValid(res,target)){
                if(length> right-left)
                {
                    start=left;
                    length=right-left;
                }
                res[s[left]-'A']--;
                left++;
            }
            else{
                res[s[right]-'A']++;
                right++;
            }
        }
        while(isValid(res,target) && left<right)
        {
                if(length > right-left)
                {
                    start=left;
                    length=right-left;
                }
                res[s[left]-'A']--;
                left++;
        }

    }
    
    
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length())
            return "";
        vector<int> target(58,0);
        for(int index=0;index<t.length();index++){
            target[t[index]-'A']++;
        }
        solve(s,target);
        if(start==-1)
            return "";
        return s.substr(start,length);
        
    }
};