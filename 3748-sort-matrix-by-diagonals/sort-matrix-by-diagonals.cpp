class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        for(auto &i:mp){
            if(i.first>=0){
                sort(i.second.begin(),i.second.end(),greater<int>());
            }
            else{
                sort(i.second.begin(),i.second.end());
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=mp[i-j].front();
               mp[i-j].erase(mp[i-j].begin());
            }
        }
        return grid;
    }
};