class Solution {
public:
    void dfs(vector<vector<bool>> &isVisited,int i,int j,vector<vector<char>> &grid){
        isVisited[i][j]=true;
        if(i>=1 && grid[i-1][j]=='1' && isVisited[i-1][j]==false){
            dfs(isVisited,i-1,j,grid);
        }
        if(i<grid.size()-1 && grid[i+1][j]=='1' && isVisited[i+1][j]==false){
            dfs(isVisited,i+1,j,grid);
        }
        if(j>=1 && grid[i][j-1]=='1' && isVisited[i][j-1]==false){
            dfs(isVisited,i,j-1,grid);
        }
        if(j<grid[0].size()-1 && grid[i][j+1]=='1' && isVisited[i][j+1]==false){
            dfs(isVisited,i,j+1,grid);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        vector<vector<bool>> isVisited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && isVisited[i][j]==false){
                    dfs(isVisited,i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};