class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<bool>> isVisited(n,vector<bool>(m,false));
        queue<vector<int>> q;
        vector<vector<int>> temp={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    isVisited[i][j]=true;
                    q.push({i,j,0});
                }
            }
        }
        while(q.size()){
            vector<int> v=q.front();
            q.pop();
            int x=v[0];
            int y=v[1];
            int count=v[2];
            for(int i=0;i<temp.size();i++){
                int x_=x+temp[i][0];
                int y_=y+temp[i][1];
                if(x_>=0 && y_>=0 && x_<n && y_<m &&isVisited[x_][y_]==false){
                    mat[x_][y_]=count+1;
                    isVisited[x_][y_]=true;
                    q.push({x_,y_,count+1});
                }
            }
        }
        return mat;
    }
};