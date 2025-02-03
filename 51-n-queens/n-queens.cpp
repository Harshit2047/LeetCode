class Solution {
public:
    bool isSafe(vector<vector<char>> board,int row,int col){
        int n=board.size();
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        int i=row;
        int j=col;
        while(i>=0 && j<n){
            if(board[i][j]=='Q') return false;
            i--;
            j++;
        }
        i=row;
        j=col;
        while(i<n && j<n){
            if(board[i][j]=='Q') return false;
            i++;
            j++;
        }
        i=row;
        j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }
        i=row;
        j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        return true;
    }
    void helper(vector<vector<char>> &board,int row,vector<vector<string>> &ans){
        int n=board.size();
        if(row==n){
            vector<string> ok;
            for(int i=0;i<n;i++){
                string s="";
                for(int j=0;j<n;j++){
                    s+=board[i][j];
                }
                ok.push_back(s);
            }
            ans.push_back(ok);
        }

        for(int j=0;j<n;j++){
            if(isSafe(board,row,j)){
                board[row][j]='Q';
                helper(board,row+1,ans);
                board[row][j]='.';

            } 
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;
        helper(board,0,ans);
        return ans;
    }
};