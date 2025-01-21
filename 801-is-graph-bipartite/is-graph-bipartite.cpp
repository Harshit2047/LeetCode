class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int> &isVisited,int start){
        isVisited[start]=1;
        queue<int> q;
        q.push(start);
        while(q.size()){
            int temp=q.front();
            q.pop();

            for(int i=0;i<graph[temp].size();i++){
                int neighbor=graph[temp][i];
                if(isVisited[neighbor]==-1){
                    isVisited[neighbor]=isVisited[temp] ? 0 : 1;
                    q.push(neighbor);
                }
                else if(isVisited[neighbor]== isVisited[temp]){
                    return false;
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> isVisited(n,-1);
        for(int i=0;i<n;i++){
            if(i == 0|| isVisited[i]==-1){
                if(!bfs(graph,isVisited,i)) return false;
            } 
        }
        return true;
    }
};