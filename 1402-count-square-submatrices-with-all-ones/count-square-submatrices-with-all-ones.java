class Solution {
    public int countSquares(int[][] arr) {
        int m=arr.length,n=arr[0].length;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                    int x=Math.min(arr[i-1][j],Math.min(arr[i][j-1],arr[i-1][j-1]));
                    if(arr[i][j]!=0) arr[i][j]+=x; 
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=arr[i][j];
            }
        }
        return ans;
    }
}