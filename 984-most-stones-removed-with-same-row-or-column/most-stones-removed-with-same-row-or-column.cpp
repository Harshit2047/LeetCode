class Solution {
public:
    void dfs(int idx,vector<bool> &isVis,vector<vector<int>> &stones){
        isVis[idx]=true;
        for(int i=0;i<stones.size();i++){
            int row=stones[idx][0];
            int col=stones[idx][1];
            if((isVis[i]==false) && (stones[i][0]==row || stones[i][1]==col)){
                dfs(i,isVis,stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool> isVis(n,false);
        int groups=0;
        for(int i=0;i<n;i++){
            if(isVis[i]==true) continue;
            else {
                dfs(i,isVis,stones);
                groups++;
            }
        }
        return n-groups;
    }
};