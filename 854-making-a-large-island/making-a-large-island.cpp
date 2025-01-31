class Solution {
public:
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
    unordered_map<int,int> mp;
    
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &isVisited, int id) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || isVisited[i][j] || grid[i][j] != 1) 
            return 0;
        
        isVisited[i][j] = true;
        grid[i][j] = id;
        int count = 1;
        
        for(auto &d : dir) {
            int i_ = i + d[0];
            int j_ = j + d[1];
            count += dfs(i_, j_, grid, isVisited, id);
        }
        
        return count;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        int id = 2, ans = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && !isVisited[i][j]) {
                    mp[id] = dfs(i, j, grid, isVisited, id);
                    ans = max(ans, mp[id]);
                    id++;
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    unordered_set<int> uniqueIds;
                    int val = 1;
                    
                    for(auto &d : dir) {
                        int i_ = i + d[0];
                        int j_ = j + d[1];
                        
                        if(i_ >= 0 && i_ < n && j_ >= 0 && j_ < n && grid[i_][j_] > 1) {
                            uniqueIds.insert(grid[i_][j_]);
                        }
                    }
                    
                    for(int id : uniqueIds) {
                        val += mp[id];
                    }
                    
                    ans = max(ans, val);
                }
            }
        }
        
        return ans;
    }
};