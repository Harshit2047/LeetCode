class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxi = stones[1]-stones[0];
        int n = stones.size();
        
        for(int i=2; i<n; i++){
            int curr = stones[i]-stones[i-2];
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};