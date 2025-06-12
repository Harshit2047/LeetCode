class Solution {
public:
    void helper(int i,vector<int> &isVisted,vector<vector<int>> &isConnected) {
        queue<int> q;
        q.push(i);
        while(q.size()){
            int idx=q.front();
            q.pop();
            vector<int> temp= isConnected[idx-1];
            for(int i=0;i<temp.size();i++){
                if(temp[i]==1 && isVisted[i+1]==false){
                    q.push(i+1);
                    isVisted[i+1]=true;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count = 0;
        int size = isConnected.size();
        vector<int> isVisted(size+1,false);
        for (int i = 1; i <= isConnected.size(); i++) {
            if (isVisted[i]==false) {
                helper(i,isVisted,isConnected);
                count++;
            }
        }
        return count;
    }
};