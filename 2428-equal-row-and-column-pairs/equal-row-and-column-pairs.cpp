class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       
        map<vector<int>, int> row, col;
        

        for(int i = 0; i < grid.size(); i++) {
            vector<int> ans;
            for(int j = 0; j < grid[0].size(); j++) {
                ans.push_back(grid[i][j]);
            }
            row[ans]++;
        }

       
        for(int i = 0; i < grid.size(); i++) {
            vector<int> ans;
            for(int j = 0; j < grid[0].size(); j++) {
                ans.push_back(grid[j][i]);
            }
            col[ans]++;
        }

        int count = 0;
        
        
        for (auto i : row) {
            if (col.find(i.first) != col.end()) {
                count += i.second * col[i.first];  
            }
        }

        return count;
    }
};
