class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> isVisited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> temp={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int j=0;j<temp.size();j++){
                    int x_=x+temp[j][0];
                    int y_=y+temp[j][1];
                    if(x_>=0 && y_>=0 && x_<n && y_<m && isVisited[x_][y_]==0 && grid[x_][y_]==1){
                        isVisited[x_][y_]=isVisited[x][y]+1;
                        q.push({x_,y_});
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isVisited[i][j]==0 && grid[i][j]==1) return -1;
                ans=max(ans,isVisited[i][j]);
            }
        }
        return ans;
    }
};