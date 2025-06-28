class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        vector<vector<int>> temp={{-1,0},{0,-1},{0,1},{1,0}};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int count=0;
                    for(int k=0;k<temp.size();k++){
                        int x_=i+temp[k][0];
                        int y_=j+temp[k][1];
                        if(x_>=0 && y_>=0 && x_<grid.size() && y_<grid[0].size() && grid[x_][y_]==1) count++;
                    }
                    ans+=4-count;
                }

            }
        }
        return ans;
    }
};