class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> temp={{-1,0},{0,-1},{1,0},{0,1}};
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> isVisted(n,vector<int>(m,false));
        int save=image[sr][sc];
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(q.size()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            int c=image[x][y];
            for(int i=0;i<temp.size();i++){
                int x_=x+temp[i][0];
                int y_=y+temp[i][1];
                if(x_>=0 &&  y_>=0 && x_<n && y_<m && isVisted[x_][y_]==false && image[x_][y_]==save){                image[x_][y_]=color;
                    isVisted[x_][y_]=true;
                    q.push({x_,y_});
                }
            }
        }
        image[sr][sc]=color;
        return image;
    }
};