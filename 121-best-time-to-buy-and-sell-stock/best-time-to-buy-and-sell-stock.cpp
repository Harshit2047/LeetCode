class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1=INT_MIN;
        int mini=INT_MAX;
        for(int ele:prices){
            if((ele-mini)>max1) max1=ele-mini;
            if(mini>ele) mini=ele;
        }
        return max1<0?0:max1;
    }
};