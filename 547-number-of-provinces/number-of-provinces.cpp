class Solution {
public:
    vector<int> parent;
    vector<int> size;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a]=find(parent[a]);
    }
    void unionSet(int a,int b){
        int leaderA=find(a);
        int leaderB=find(b);
        if(leaderA!=leaderB){
            if(size[leaderA]>size[leaderB]){
                parent[leaderB]=leaderA;
                size[leaderA]+=size[leaderB];
            }
            else{
                parent[leaderA]=leaderB;
                size[leaderB]+=size[leaderA];
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=1;i<parent.size();i++){
            parent[i]=i;
            size[i]=1;
        }
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected.size();j++){
                if(i!=j && isConnected[i][j]==1){
                    unionSet(i+1,j+1);
                }
            }
        }
        int count=0;
        for(int i=1;i<parent.size();i++){
            if(parent[i]==i) count++;
        }
        return count;
    }
};