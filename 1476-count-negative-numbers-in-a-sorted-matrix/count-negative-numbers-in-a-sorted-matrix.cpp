class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int k=0;k<grid.size();k++){
            int i=0;
            int j=grid[k].size()-1;
            while(i<=j){
                int mid=i+(j-i)/2;
                if(grid[k][mid]<0){
                    j=mid-1;
                }
                else if(grid[k][mid]>=0){
                    i=mid+1;
                }
            }
           
            count+=(grid[k].size()-i);
        }
        return count;
    }
};