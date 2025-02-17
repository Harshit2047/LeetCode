class Solution {
public:
    void helper(string tiles,string ans,unordered_set<string> &s){
        if(tiles.size()==0) return ;
        for(int i=0;i<tiles.size();i++){
            ans+=tiles[i];
            s.insert(ans);
            string left=tiles.substr(0,i)+tiles.substr(i+1);
            helper(left,ans,s);
            ans.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> s;
        helper(tiles,"",s);
        for(auto i:s){
            cout<<i<<" ";
        }
        return s.size();
    }
};