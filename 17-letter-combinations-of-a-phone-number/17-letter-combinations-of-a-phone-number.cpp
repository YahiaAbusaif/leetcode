class Solution {
    vector<string> allLetters;
    void init()
    {
        allLetters = vector<string>(10);
        allLetters[2]="abc";
        allLetters[3]="def";
        allLetters[4]="ghi";
        allLetters[5]="jkl";
        allLetters[6]="mno";
        allLetters[7]="pqrs";
        allLetters[8]="tuv";
        allLetters[9]="wxyz";
        
    }
    bool increamnt(string& cnt,const string & digits)
    {
        for(int i=0;i<digits.size();i++)
        {
            if(cnt[i]-'0'+1< allLetters[digits[i]-'0'].size())
            {
                cnt[i]++;
                return true;
            }
            cnt[i]='0';
        }
        return false;
    }
public:
    vector<string> letterCombinations(string digits) {
        init();
        string counter="00000";
        vector<string> res;
        if(digits =="")
            return res;
        do
        {
            string ans="";
            for(int i=0;i<digits.size();i++)
            {
                ans+= allLetters[digits[i]-'0'][counter[i]-'0'];

            }            
            res.push_back(ans);
        }while(increamnt(counter,digits));
        
        return res;
    }
};