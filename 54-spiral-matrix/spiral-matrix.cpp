class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=0;
        int col=matrix[0].size()-1;
        int RevRow=matrix.size()-1;
        int StratCol=0;
        vector<int> ans;
        while(row<=RevRow && StratCol<=col){
            for(int i=StratCol;i<=col;i++){
                ans.push_back(matrix[row][i]);
            }
            row++;
            for(int j=row;j<=RevRow;j++){
                ans.push_back(matrix[j][col]);
            }
            col--;
             if (row <= RevRow) {
                for (int i = col; i >= StratCol; i--)
                    ans.push_back(matrix[RevRow][i]);
                RevRow--;
            }

            
            if (StratCol <= col) {
                for (int j = RevRow; j >= row; j--)
                    ans.push_back(matrix[j][StratCol]);
                StratCol++;
            }
            
        }
        return ans;
    }
};