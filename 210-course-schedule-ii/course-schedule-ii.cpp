class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> freq(n);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            freq[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) q.push(i);
        }
        vector<int> ans;
        while(q.size()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<adj[temp].size();i++){
                int neighbor=adj[temp][i];
                freq[neighbor]--;
                if(freq[neighbor]==0) q.push(neighbor);
            }
        }
        if (ans.size()==n)  return ans;
        return {};
    }
};