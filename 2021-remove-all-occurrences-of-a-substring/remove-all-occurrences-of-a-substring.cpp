class Solution {
public:
    bool check(stack<char> st,string part){
        for(int i=part.length()-1;i>=0;i--){
            if(st.top()!=part[i]) return false;
            else st.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            st.push(s[i]);
            if(st.size()>=part.length() && check(st,part)){
                for(int i =0;i<part.length();i++){
                    st.pop();
                }
            }
        }
        string ans="";
        while(st.size()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};