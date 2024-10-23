class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> mp;
        stringstream sx(s);
        string word;
        int i=0;
        int length=0;
        while(sx>>word){
            length++;
        }
        if(pattern.length()>length || pattern.length()<length) return false;
         stringstream ss(s);
        
        while(ss>>word){
            
            if(mp.find(pattern[i])==mp.end()){
                for(auto i:mp){
                    if(word==i.second){
                        return false;
                    }
                }
                mp[pattern[i]]=word;
                

            }
            else{
                if(mp[pattern[i]]!=word) {
                    return false;
                }
                
            }
            i++;
        }
    return true;
    }
};