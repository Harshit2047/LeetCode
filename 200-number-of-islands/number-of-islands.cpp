class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>&isVisited,pair<int,int> p){
        queue<pair<int,int>> q;
        q.push(p);
        isVisited[p.first][p.second]=true;
        while(q.size()>0){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            if( i+1<grid.size() && !isVisited[i+1][j] && grid[i+1][j]=='1'){
                q.push({i+1,j});
                isVisited[i+1][j]=true;
            }
             if(i-1>=0 && !isVisited[i-1][j] && grid[i-1][j]=='1'){
                q.push({i-1,j});
                isVisited[i-1][j]=true;
            }
             if(j+1<grid[0].size() && !isVisited[i][j+1] && grid[i][j+1]=='1'){
                q.push({i,j+1});
                isVisited[i][j+1]=true;
            }
             if(j-1>= 0 && !isVisited[i][j-1] && grid[i][j-1]=='1'){
                q.push({i,j-1});
                isVisited[i][j-1]=true;
            }
            
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> isVisited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!isVisited[i][j] && grid[i][j]=='1'){
                    pair<int,int> p={i,j};
                    bfs(grid,isVisited,p);
                    count++;
                }
            }
        }
        return count;
    }
};