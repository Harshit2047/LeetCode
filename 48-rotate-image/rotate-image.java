class Solution {
    public void rotate(int[][] arr) {
        int n=arr.length;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int t=arr[j][i];
                arr[j][i]=arr[i][j];
                arr[i][j]=t;
            }
        }
      
            for (int i = 0; i < n; i++) {
            for (int j = 0, k = n - 1; j < k; j++, k--) {
                int temp = arr[i][j];
                arr[i][j] = arr[i][k];
                arr[i][k] = temp;
            }
        }

        
    }
}