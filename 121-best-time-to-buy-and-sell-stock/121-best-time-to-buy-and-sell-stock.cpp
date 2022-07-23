class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, maxP=prices[prices.size()-1];
        for(int index=prices.size()-2;index>=0;index--){
            ans= max(ans,maxP-prices[index]);
            maxP=max(maxP,prices[index]);
        }
        return ans;
    }
};