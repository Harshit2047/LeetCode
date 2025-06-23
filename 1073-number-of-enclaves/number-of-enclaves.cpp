class Solution {
public:
    void helper(vector<vector<int>> &grid,vector<vector<bool>> &isVisited ,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<int>> temp={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<temp.size();i++){
                int x_=x+temp[i][0];
                int y_=y+temp[i][1];
                if(x_>=0 && y_>=0 && x_<n && y_<m && isVisited[x_][y_]==false && grid[x_][y_]==1){
                    isVisited[x_][y_]=true;
                    q.push({x_,y_});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> isVisited(n,vector<bool>(m,false));
        for(int i=0;i<m;i++){
            if(isVisited[0][i]==false && grid[0][i]==1) helper(grid,isVisited,0,i);
        }
        for(int i=0;i<m;i++){
            if(isVisited[n-1][i]==false && grid[n-1][i]==1) helper(grid,isVisited,n-1,i);
        }
        for(int i=0;i<n;i++){
            if(isVisited[i][0]==false && grid[i][0]==1) helper(grid,isVisited,i,0);
        }
        for(int i=0;i<n;i++){
            if(isVisited[i][m-1]==false && grid[i][m-1]==1) helper(grid,isVisited,i,m-1);
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(isVisited[i][j]==false && grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};