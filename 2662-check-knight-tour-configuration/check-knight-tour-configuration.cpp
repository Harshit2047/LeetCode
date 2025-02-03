class Solution {
public:
    vector<vector<int>> dir{{2,-1},{2,+1},{-2,-1},{-2,1},{-1,2},{1,2},{-1,-2},{1,-2}};
    bool helper(vector<vector<int>> &grid , int i,int j,int num){
        int n=grid.size();
        if(num==n*n-1) return true;
        bool temp=false;
        for(auto x:dir){
            int i_=i+x[0];
            int j_=j+x[1];
            if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] == num + 1){
                if(helper(grid,i_,j_,num+1)){
                    temp=true;
                    break;
                } 
            }
        }
        return temp;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0) return false;
        return helper(grid,0,0,0);
        
    }
};