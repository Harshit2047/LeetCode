class Solution {
public:
    void bfs(vector<bool> &isVisited,vector<vector<int>>& rooms,int idx){
        queue<int> q;
        q.push(idx);
        while(q.size()>0){
            int idx=q.front();
            q.pop();
            vector<int> temp=rooms[idx];
            for(int i=0;i<temp.size();i++){
               if(isVisited[temp[i]]==false){
                 isVisited[temp[i]]=true;
                  q.push(temp[i]);
               }
            }
        }
    }
    void dfs(vector<bool> &isVisited,vector<vector<int>> &rooms,int idx){
        vector<int> temp=rooms[idx];
        for(int i=0;i<temp.size();i++){
            if(isVisited[temp[i]]==false){
                isVisited[temp[i]]=true;
                dfs(isVisited,rooms,temp[i]);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> isVisited(n,false);
        isVisited[0]=true;
        dfs(isVisited,rooms,0);
        for(int i=0;i<isVisited.size();i++){
            if( isVisited[i]==false) return false;
        }
        return true;
    }
};