class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> RevAdj(graph.size(),vector<int>());
        vector<int> freq(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                RevAdj[graph[i][j]].push_back(i);
                freq[i]++;
            }
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
            for(int i=0;i<RevAdj[temp].size();i++){
                int neighbor=RevAdj[temp][i];
                freq[neighbor]--;
                if(freq[neighbor]==0) q.push(neighbor);
            }

        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};