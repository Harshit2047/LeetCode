class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> v(cost.size());
        v[0]=cost[0];
        if(n>1) v[1]=cost[1];
        for(int i=2;i<=cost.size()-1;i++){
            v[i]=cost[i]+min(v[i-1],v[i-2]);
        }
    return min(v[n - 1], v[n - 2]);
        
    }
};