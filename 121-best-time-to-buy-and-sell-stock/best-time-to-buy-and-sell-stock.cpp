class Solution {
public:
    int helper(vector<int> &prices,int idx,int minBuy){
        if(idx==prices.size()) return 0;
        int currentProfit=prices[idx]-minBuy;
        minBuy=min(minBuy,prices[idx]);
        int futureSell=helper(prices,idx+1,minBuy);
        return max(currentProfit,futureSell);
    }
    int maxProfit(vector<int>& prices) {
        // int profit=0;
        // int minBuy=INT_MAX;
        // for(int i=0;i<prices.size();i++){
        //     if(minBuy>prices[i]){
        //         minBuy=prices[i];
        //     }
        //     profit=max(profit,prices[i]-minBuy);
        // }
        return helper(prices,1,prices[0]);
    }
};