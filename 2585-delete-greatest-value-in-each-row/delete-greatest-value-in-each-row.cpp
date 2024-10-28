class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
         int n = grid.size();
        for(int i=0;i<n;i++){
            sort(grid[i].rbegin(),grid[i].rend());
        }
        int m = grid[0].size();
       
        int ans = 0;
        int k =0;
        while(m--)
        {
            int maxi = 0;
            for(int i=0;i<n;i++)
            {
                int largest = grid[i][k];
                maxi = max(maxi,largest);
            }
            k++;
            ans+=maxi;
        }
        return ans;
    }
};