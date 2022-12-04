class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, size=prices.size()-1;
        for(int index=0;index<size;index++){
            if(prices[index]<prices[index+1])
                ans+=(prices[index+1]-prices[index]);
        }
        return ans;
    }
};