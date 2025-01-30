class Solution {
public:
    int helper(vector<vector<int>> &grid,vector<vector<bool>> &isVisited,int i,int j,int n,int m,int count,int ok){
        if(i<0 || j<0) return 0;
        if(i>=n || j>=m) return 0;
        if(grid[i][j]==-1) return 0;
        if(isVisited[i][j]==true) return 0;
        if(grid[i][j]==2 && count==ok) return 1;
        if(grid[i][j]==0) ok++;
        isVisited[i][j]=true;
        int down=helper(grid,isVisited,i+1,j,n,m,count,ok); 
        int up=helper(grid,isVisited,i-1,j,n,m,count,ok); 
        int left=helper(grid,isVisited,i,j-1,n,m,count,ok); 
        int right=helper(grid,isVisited,i,j+1,n,m,count,ok); 
        isVisited[i][j]=false;
        return down+up+left+right;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int a=0;
        int b=0;
        int count=0;
        vector<vector<bool>> isVisited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    a=i;
                    b=j;
                }
                else if(grid[i][j]==0) count++;
            }
        }
        int ok=0;
        return helper(grid,isVisited,a,b,n,m,count,ok);
    }
};