class Pair{
    int i,j;
    Pair(int i,int j){
        this.i=i;
        this.j=j;
    }
}
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m=mat.length,n=mat[0].length;
        int[][]vis=new int[m][n];
        Queue<Pair>q=new LinkedList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.add(new Pair(i,j));
                }
                else{
                    vis[i][j]=Integer.MAX_VALUE;
                }
            }
        }
        while(q.size()>0){
            Pair p=q.remove();
            int i=p.i,j=p.j;
            if(i+1<m && mat[i+1][j]==1 && vis[i][j]+1<vis[i+1][j]){
                vis[i+1][j]=vis[i][j]+1;
                q.add(new Pair(i+1,j));
            }
            if(j+1<n && mat[i][j+1]==1 && vis[i][j]+1<vis[i][j+1]){
                vis[i][j+1]=vis[i][j]+1;
                q.add(new Pair(i,j+1));
            }
            if(i-1>=0 && mat[i-1][j]==1 && vis[i][j]+1<vis[i-1][j]){
                vis[i-1][j]=vis[i][j]+1;
                q.add(new Pair(i-1,j));
            }
            if(j-1>=0 && mat[i][j-1]==1 && vis[i][j]+1<vis[i][j-1]){
                vis[i][j-1]=vis[i][j]+1;
                q.add(new Pair(i,j-1));
            }

        }
        return vis;
    }
}