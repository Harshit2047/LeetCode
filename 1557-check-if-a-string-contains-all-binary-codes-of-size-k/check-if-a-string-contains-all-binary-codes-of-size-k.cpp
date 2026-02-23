class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        int i=0;
        if(k > s.length()) return false;
        while(i<=s.length()-k){
            int j=i;
            string temp="";
            while(j-i+1<=k && j<s.length()){
                temp+=s[j];
                j++;
            } 
            st.insert(temp);
            i++;
        }
        return (pow(2,k) == st.size()) ;
    }
};