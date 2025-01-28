class Solution {
public:
    int bfs(vector<vector<int>>& grid,int i,int j,vector<vector<bool>> &isVisited){
         vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
         queue<pair<int,int>> q;
         isVisited[i][j]=true;
         q.push({i,j});
         int ans=0;
         while(q.size()){
            auto temp=q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            ans= ans+grid[i][j];
            for(int x=0;x<dir.size();x++){
                int i_=i+dir[x][0];
                int j_=j+dir[x][1];
                if((i_>=0 && i_<grid.size() )&& (j_>=0 && j_<grid[0].size())){
                    if(grid[i_][j_]!=0 && isVisited[i_][j_]==false){
                        isVisited[i_][j_]=true;
                        q.push({i_,j_});
                    }
                }

            }
         }
         return ans;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int Maxans=INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                vector<vector<bool>> isVisited(grid.size(),vector<bool>(grid[0].size(),false));
                if(grid[i][j]>0 && isVisited[i][j]==false){
                   Maxans=max(Maxans,bfs(grid,i,j,isVisited));
                }
            }
        }
        return Maxans==INT_MIN ? 0 : Maxans;
    }
};