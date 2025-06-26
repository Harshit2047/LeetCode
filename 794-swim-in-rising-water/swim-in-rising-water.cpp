class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> isVisited(n, vector<bool>(n, false));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0});  
        
        vector<vector<int>> dirs = {{-1,0}, {0,-1}, {0,1}, {1,0}};
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int val = curr[0];
            int x = curr[1];
            int y = curr[2];
            
          
            
            if (x == n - 1 && y == n - 1) return val;
            
            for (auto d : dirs) {
                int x_ = x + d[0];
                int y_ = y + d[1];
                
                if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < n && isVisited[x_][y_]==false) {
                    pq.push({max(val, grid[x_][y_]), x_, y_});
                    isVisited[x_][y_] = true;
                }
            }
        }
        
        return -1;
    }
};
