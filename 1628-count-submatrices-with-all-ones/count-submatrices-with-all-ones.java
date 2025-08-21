class Solution {
    public int numSubmat(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        
        // Step 1: compute horizontal consecutive 1s
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 1) {
                    mat[i][j] += mat[i][j - 1]; // extend width
                }
            }
        }

        int count = 0;
        
        // Step 2: count submatrices
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] > 0) {
                    int minWidth = mat[i][j];
                    for (int k = i; k >= 0; k--) { // go upwards
                        if (mat[k][j] == 0) break;
                        minWidth = Math.min(minWidth, mat[k][j]);
                        count += minWidth;
                    }
                }
            }
        }
        
        return count;
    }
}
