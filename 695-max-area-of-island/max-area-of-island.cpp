class Solution {
public:
    int helper(vector<vector<int>>& grid , vector<vector<bool>>& isVisited,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
          isVisited[i][j]=true;
        vector<vector<int>> temp={{-1,0},{0,-1},{0,1},{1,0}};
        q.push({i,j});
        int count=1;
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<temp.size();i++){
                int x_=x+temp[i][0];
                int y_=y+temp[i][1];
                if(x_>=0 && y_>=0 && x_<n && y_<m && grid[x_][y_]==1 && isVisited[x_][y_]==false){
                    count++;
                    isVisited[x_][y_]=true;
                    q.push({x_,y_});
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> isVisited(n,vector<bool>(m,false));
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && isVisited[i][j]==false){
                    int temp=helper(grid,isVisited,i,j);
                    ans=max(ans,temp);
                }
            }
        }
        return ans==INT_MIN ? 0 : ans;
    }
};