class Solution {
public:
    // void helper(int i,vector<int> &isVisted,vector<vector<int>> &isConnected)
    // {
    //     queue<int> q;
    //     q.push(i);
    //     while(q.size()){
    //         int idx=q.front();
    //         q.pop();
    //         vector<int> temp= isConnected[idx-1];
    //         for(int i=0;i<temp.size();i++){
    //             if(temp[i]==1 && isVisted[i+1]==false){
    //                 q.push(i+1);
    //                 isVisted[i+1]=true;
    //             }
    //         }
    //     }
    // }
    // void dfs(int idx,vector<vector<int>> &isConnected,vector<int> &isVisted){
    //     if(isVisted[idx]==true || idx>isConnected.size()-1) return;
    //     vector<int> temp=isConnected[idx];
    //     for(int i=0;i<temp.size();i++){
    //         if(isVisted[i]==false && temp[i]==1){
    //              isVisted[i]=true;
    //             dfs(i,isConnected,isVisted);

    //         }
    //     }
    // }

    void dfs(int u, vector<vector<int>>& isConnected, vector<int>& isVisted) {
        if (isVisted[u])
            return;
        isVisted[u] = true;

        for (int v = 0; v < isConnected[u].size(); ++v) {
        if (isConnected[u][v] == 1 && !isVisted[v]) {
            dfs(v, isConnected, isVisted);
        }
    }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int size = isConnected.size();
        vector<int> isVisted(size + 1, false);

        for (int i = 0; i < isConnected.size(); i++) {
            if (isVisted[i] == false) {
                dfs(i, isConnected, isVisted);
                count++;
            }
        }
        return count;
    }
};