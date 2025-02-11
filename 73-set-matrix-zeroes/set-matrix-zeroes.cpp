class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<pair<int, int>> s;
        
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    s.insert({i, j});
                }
            }
        }

        for(auto x : s) {
            int i_ = x.first;
            int j_ = x.second;
            
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][j_] = 0;
            }
            for(int j = 0; j < matrix[0].size(); j++) {
                matrix[i_][j] = 0;
            }
        }
    }
};
