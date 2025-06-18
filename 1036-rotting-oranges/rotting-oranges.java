class Solution {
    class Pair{
        int i,j;
        Pair(int i,int j){
            this.i=i;
            this.j=j;
        }
    }
    public int orangesRotting(int[][] grid) {
        int m=grid.length,n=grid[0].length;
        Queue<Pair>q=new LinkedList<>();
        int vis[][]=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.add(new Pair(i,j));
                }
            }
        }
        while(q.size()>0){
            Pair p=q.remove();
            int i=p.i,j=p.j;
            if(i+1<m && vis[i+1][j]==0 && grid[i+1][j]==1){
                q.add(new Pair(i+1,j));
                vis[i+1][j]=vis[i][j]+1;
            } 
            if(j+1<n && vis[i][j+1]==0 && grid[i][j+1]==1){
                q.add(new Pair(i,j+1));
                vis[i][j+1]=vis[i][j]+1;
            } 
            if(i-1>=0 && vis[i-1][j]==0 && grid[i-1][j]==1){
                q.add(new Pair(i-1,j));
                vis[i-1][j]=vis[i][j]+1;
            } 
             if(j-1>=0 && vis[i][j-1]==0  && grid[i][j-1]==1){
                q.add(new Pair(i,j-1));
                vis[i][j-1]=vis[i][j]+1;
            }  
        }
        int max=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1) return -1;
                max=Math.max(max,vis[i][j]);
            }
        }
        return max;
        
        
    }
}