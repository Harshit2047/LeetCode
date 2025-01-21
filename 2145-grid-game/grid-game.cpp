class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        vector<int> v=grid[0];
        long long firstRowSum=0;
        for(int i=0;i<v.size();i++){
            firstRowSum+=v[i];
        }
        long long ans=LLONG_MAX;
        long long secondRowSum=0;
        for(int i=0;i<grid[0].size();i++){
            firstRowSum-=grid[0][i];
            long long temp=max(firstRowSum,secondRowSum);
            secondRowSum+=grid[1][i];
            ans=min(ans,temp);
        }
        return ans;
    }
};