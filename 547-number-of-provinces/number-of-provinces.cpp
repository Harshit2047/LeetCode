class Solution {
public:
    void helper(vector<vector<int>> &isConnected,vector<bool> &isVisited,int idx){
        queue<int> q;
        q.push(idx);
        while(q.size()){
            int currIdx=q.front();
            isVisited[currIdx]=true;
            q.pop();
            for(int i=0;i<isConnected[currIdx].size();i++){
                if(isConnected[currIdx][i]==1 && isVisited[i]==false){
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> isVisited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(isVisited[i]==false){
                helper(isConnected,isVisited,i);
                count++;
            }
        }
        return count;

    }
};