class Solution {
public:
    void healper(vector<vector<char>> &board,vector<vector<bool>> &isVisited,int i,int j){
         int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        vector<vector<int>> temp={{1,0},{0,1},{-1,0},{0,-1}};
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<temp.size();i++){
                int x_=x+temp[i][0];
                int y_=y+temp[i][1];
                if(x_>=0 && y_>=0 && x_<n && y_<m && isVisited[x_][y_]==false && board[x_][y_]=='O'){
                    isVisited[x_][y_]=true;
                    q.push({x_,y_});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> isVisited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && board[i][j]=='O' && isVisited[i][j]==false) healper(board,isVisited,i,j);
            }
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && isVisited[i][j]==false) board[i][j]='X';
            }
        }
    }
};