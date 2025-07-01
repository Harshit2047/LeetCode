class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            if(grid[0][0]==1) return -1;
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int>> temp={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{1,1},{-1,+1},{1,-1}};
            priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
            vector<vector<bool>> isVisited(n,vector<bool>(m,false));
            int count=1;
            pq.push({count,0,0});
            while(pq.size()){
                vector<int> xd=pq.top();
                pq.pop();
                int count=xd[0];
                int x=xd[1];
                int y=xd[2];
                if(x==n-1 && y==m-1) return count;
                for(int i=0;i<temp.size();i++){
                    int x_=x+temp[i][0];
                    int y_=y+temp[i][1];
                    if(x_>=0 && y_>=0 && x_<n && y_<m){
                        if(grid[x_][y_]==0 &&isVisited[x_][y_]==false){
                            isVisited[x_][y_]=true;
                            pq.push({count+1,x_,y_});
                        }
                    }
                }
            }
        return -1;
    }
};