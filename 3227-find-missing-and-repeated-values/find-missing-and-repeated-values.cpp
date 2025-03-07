class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n=grid.size()*grid.size();
        long long F=(n*(n+1))/2;
        long long I=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                I+=grid[i][j];
            }
        }
        long long SF=((n*(n+1)*((2*n)+1)))/6;
        long long SI=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                SI+=pow(grid[i][j],2);
            }
        }
        long long eq1=F-I;
        long long eq2=(SF-SI)/eq1;
        long long ansFirst=(eq2-eq1)/2;
        long long ansSecond=eq1+ansFirst;
        return {(int)ansFirst,(int)ansSecond};

    }
};