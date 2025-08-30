class Solution {
    boolean helper(int row,int col,char ch,char[][] board){
        for(int i=0;i<9;i++){
            if(board[i][col]==ch) return false;
        }
        for(int j=0;j<9;j++){
            if(board[row][j]==ch) return false;
        }

        row=(row/3)*3;
        col=(col/3)*3;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]==ch) return false;
            }
        }
        return true;

    }
    public boolean isValidSudoku(char[][] board) {
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='.') continue;
                else{
                    char ch=board[i][j];
                    board[i][j]='.';
                    if(!helper(i,j,ch,board)) return false;
                    board[i][j]=ch;
                }
            }
        }
        return true;
    }
}