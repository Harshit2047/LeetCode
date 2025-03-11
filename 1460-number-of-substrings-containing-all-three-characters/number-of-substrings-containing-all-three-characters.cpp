class Solution {
public:
    int numberOfSubstrings(string s) {
            int ans=0;
            int j=0;
            int k=0;
            int n=s.size();
            unordered_map<char,int> mp;
            while(k<s.length()){    
                mp[s[k]]++;
                while(mp.size()==3){
                    ans+=(n-k);
                    mp[s[j]]--;
                    if(mp[s[j]]==0) mp.erase(s[j]);
                    j++;
                }
                k++;

            }
        return ans;
        
    }
};