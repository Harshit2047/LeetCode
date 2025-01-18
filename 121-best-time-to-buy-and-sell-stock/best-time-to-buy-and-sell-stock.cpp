class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=INT_MIN;
        int minimum=INT_MAX;
        for(int i=0;i<prices.size();i++){
            int val=prices[i];
            minimum=min(minimum,prices[i]);
            ans=max(ans,val-minimum);
            
            
        }
        return  ans;
        
    }
};