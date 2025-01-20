class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Map each value in mat to its position (row, col)
        unordered_map<int, pair<int, int>> pos;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pos[mat[i][j]] = {i, j};
            }
        }

        // Track the count of remaining cells to paint for each row and column
        vector<int> row(n, m);
        vector<int> col(m, n);

        // Process each element in arr
        for (int i = 0; i < arr.size(); i++) {
            int r = pos[arr[i]].first; // Get row position
            int c = pos[arr[i]].second; // Get column position

            row[r]--; // Decrement the remaining cells in the row
            col[c]--; // Decrement the remaining cells in the column

            // Check if the row or column is fully painted
            if (row[r] == 0 || col[c] == 0) {
                return i;
            }
        }

        return -1; // Should not reach here since the problem guarantees a solution
    }
};
