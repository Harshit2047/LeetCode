class Solution {
public:
    // void bfs(vector<bool> &isVisited,vector<vector<int>>& isConnected,int i){
    //     int n=isConnected[0].size();
    //     isVisited[i]=true;
    //     queue<int> q;
    //     q.push(i);
    //     while(q.size()>0){
    //         int temp=q.front();
    //         q.pop();
    //         for(int j=0;j<n;j++){
    //             if(isVisited[j]!=true && isConnected[temp][j]==1){
    //                 q.push(j);
    //                 isVisited[j]=true;
    //             }
    //         }
            
    //     }
    // }
    void dfs(vector<bool> &isVisited,vector<vector<int>>& isConnected,int i){
        isVisited[i]=true;
        for(int j=0;j<isConnected[0].size();j++){
            if(isConnected[i][j]==1 && isVisited[j]==false){
                dfs(isVisited,isConnected,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> isVisited(n,false);
        for(int i=0;i<n;i++){
            if(!isVisited[i]){
                dfs(isVisited,isConnected,i);
                count++;
            }
        }
        return count;
    }
};