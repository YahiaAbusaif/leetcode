class Solution {
    
public:
    string decodeString(string s) {
        int index=0;
        string res="";
        while(index<s.size()){
            if(s[index]>='0' && s[index]<='9')
            {
                string number="";
                while(s[index]!='[')
                {
                    number+=s[index++];
                    if(index>=s.size()){
                        return res+number;
                    }
                }
                int times=stoi(number);
                string chars="";
                int sum=-1;
                index++;
                while(sum<0){
                    if(s[index]=='[')
                        sum--;
                    if(s[index]==']')
                        sum++;
                    if(sum!=0)
                        chars+=s[index++];
                }
                string ans= decodeString(chars);
                index++;
                while(times){
                    res+=ans;
                    times--;
                }                
            }
            else{
                res+=s[index++];
            }
        }
        return res;
    }
};