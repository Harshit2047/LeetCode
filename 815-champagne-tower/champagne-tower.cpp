class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> v(query_row+1, vector<double>(query_row+1, 0));
        if(poured == 0) return 0.0;

        v[0][0] = poured;   

        for(int i = 1; i < v.size(); i++){
            for(int j = 0; j < i; j++){   
                if(v[i-1][j] > 1){        
                    double extra = v[i-1][j] - 1;
                    v[i][j]     += extra / 2;
                    v[i][j + 1] += extra / 2;
                }
            }
        }

        return min(1.0, v[query_row][query_glass]); 
    }
};
