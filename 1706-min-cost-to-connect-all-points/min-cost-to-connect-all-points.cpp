class Solution {
public:
    struct cmp {
        bool operator()(const vector<int> &a, const vector<int> &b) { 
            return a[2] > b[2];
        }
    };
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ans = 0;
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        vector<bool> isVisited(points.size(), false);
        pq.push({0, -1, 0});
        
        while (!pq.empty()) { 
            vector<int> v = pq.top();
            pq.pop();
            int temp = v[0];
            int parent = v[1];
            int wt = v[2];

            if (isVisited[temp]) continue; 
            ans += wt;
            isVisited[temp] = true;

            for (int i = 0; i < points.size(); i++) { 
                if (i == temp || isVisited[i]) continue; 

                int x1 = points[temp][0];
                int y1 = points[temp][1];
                int x2 = points[i][0];
                int y2 = points[i][1];
                int weight = abs(x1 - x2) + abs(y1 - y2);

                pq.push({i, temp, weight}); 
            }
        }
        return ans;
    }
};
