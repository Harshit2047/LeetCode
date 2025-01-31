class Solution {
public:
     vector<int> parent;
    vector<int> size;

    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return a[2] > b[2]; // Min-heap based on edge weight
        }
    };

    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]); // Path compression
    }

    void unionSet(int a, int b) {
        int leaderA = find(a);
        int leaderB = find(b);
        if (leaderA != leaderB) {
            if (size[leaderA] > size[leaderB]) {
                parent[leaderB] = leaderA;
                size[leaderA] += size[leaderB];
            } else {
                parent[leaderA] = leaderB;
                size[leaderB] += size[leaderA];
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<points.size();i++){
            parent[i]=i;
        }
        priority_queue<vector<int>,vector<vector<int>>,cmp> pq;
        for(int u=0;u<points.size();u++){
            for(int v=u+1;v<n;v++){
                int x1=points[u][0];
                int y1=points[u][1];
                int x2=points[v][0];
                int y2=points[v][1];
                int dis=abs(x1-x2)+abs(y1-y2);
                pq.push({u,v,dis});
            }
        }
        int ans=0;
        
        while(pq.size()){
            auto temp=pq.top();
            pq.pop();
            int u=temp[0];
            int v=temp[1];
            int cost=temp[2];
            if(find(u)!=find(v)){
                ans=ans+cost;
                unionSet(u,v);
            }

        }

        return ans;
    }
};