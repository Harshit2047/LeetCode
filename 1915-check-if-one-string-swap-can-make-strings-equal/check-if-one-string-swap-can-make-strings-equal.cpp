class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
       vector<int> temp;
       for(int i=0;i<s1.length();i++){
        if(s1[i]!=s2[i]){
            temp.push_back(i);
        }
        
       }
        return temp.size() == 2 && s1[temp[0]] == s2[temp[1]] && s1[temp[1]] == s2[temp[0]];
    }
};