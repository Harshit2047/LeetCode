class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minBuy=INT_MAX;
        for(int i=0;i<prices.size();i++){
            if(minBuy>prices[i]){
                minBuy=prices[i];
            }
            profit=max(profit,prices[i]-minBuy);
        }
        return profit;
    }
};