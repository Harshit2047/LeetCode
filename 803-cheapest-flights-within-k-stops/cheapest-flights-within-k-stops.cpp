class Solution {
public:
    struct compare{
        bool operator()(const vector<int> &a,const vector<int>&b){
            if(a[2]==b[2]) return a[1]>b[1];
            return a[2]>b[2];
        }
    };
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> costArr(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        costArr[src]=0;
        pq.push({src,0,1});
        while(pq.size()){
            vector<int> temp=pq.top();
            pq.pop();
            int s=temp[0];
            int cost=temp[1];
            int count=temp[2];
            if(count>k+1) continue;
            for(int i=0;i<adj[s].size();i++){
                int neighbor=adj[s][i].first;
                int currCost=adj[s][i].second;
                int total=currCost+cost;
                if(costArr[neighbor]>total){
                    costArr[neighbor]=total;
                    pq.push({neighbor,total,count+1});
                }
            }
        }
        int ans=costArr[dst];
        if(ans==INT_MAX) return -1;
        return ans;
        
    }
};