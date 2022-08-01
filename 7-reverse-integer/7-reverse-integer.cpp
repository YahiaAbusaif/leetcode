class Solution {
public:
    int reverse(int x) {
        int sign= x<0;
        x=abs(x);
        long long ans=0;
        while(x)
        {
            ans=ans*10 + (x%10);
            x=x/10;
        }
        if(sign ==1)
            ans=ans*-1;
        if(ans> 2147483647 || ans< -2147483648)
            return 0;
        return ans;
    }
};