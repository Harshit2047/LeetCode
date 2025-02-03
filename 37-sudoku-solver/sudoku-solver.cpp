class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>> & grid,char val){
        for(int i=0;i<9;i++){
            if(grid[i][col]==val) return false;
        }

        for(int j=0;j<9;j++){
            if(grid[row][j]==val) return false;
        }
        int x=(row/3)*3;
        int y=(col/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(grid[i][j]==val) return false;
            }
        }
        return true;
    }
    void helper(vector<vector<char>>& board, vector<vector<char>> &temp, int i,int j) {
        if(i==9){
            temp.assign(board.begin(),board.end());
            return;
        }
        if(board[i][j]!='.'){
            if(j!=8) helper(board,temp,i,j+1);
            else helper(board,temp,i+1,0);
        }
        else if (board[i][j] == '.') {
            for (char x = '1'; x <= '9'; x++) {
                if (isSafe(i, j, board,x)) {
                    board[i][j] = x;
                    if (j != 8)helper(board, temp, i, j+1);
                    else helper(board, temp, i + 1, 0);

                }
                 board[i][j]='.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> temp = board;
         helper(board, temp, 0, 0);
        board.assign(temp.begin(),temp.end());
    }
};