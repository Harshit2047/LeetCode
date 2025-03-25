class Solution {
public:
    bool isSafe(int num,vector<vector<char>> &board,int row,int col){
        for(int i=0;i<9;i++){
            if((num+'0')==board[i][col]) return false;
        }
        for(int j=0;j<9;j++){
            if((num+'0')==board[row][j]) return false;
        }
        int Srow=(row/3)*3;
        int Scol=(col/3)*3;
        for(int i=Srow;i<Srow+3;i++){
            for(int j=Scol;j<Scol+3;j++){
                if((num+'0')==board[i][j]) return false;
            }
        }
        return true;
    }
    void helper(vector<vector<char>> &board,int row,int col,vector<vector<char>> &ans){
        if (row == 9) {
            ans = board;
            return;
        }
        if (col == 9) { 
            helper(board, row + 1, 0, ans);
            return;
        }
        if (board[row][col] != '.') {
            helper(board, row, col + 1, ans);
            return;
        }
        for (int num = 1; num <= 9; num++) {
            if (isSafe(num, board, row, col)) {
                board[row][col] = num + '0';
                helper(board, row, col + 1, ans);
                board[row][col] = '.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> ans(9,vector<char>(9,'.'));
        helper(board,0,0,ans);
        board.assign(ans.begin(),ans.end());
    }
};