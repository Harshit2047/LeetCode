class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans="";
        for(int i=0;i<s.length();i++){
            if(st.size()==0){
                st.push(s[i]);
            }
            else{
                if(s[i]=='('){
                    ans+=s[i];
                    st.push(s[i]);
                }
                else if(s[i]==')'){
                    if(st.size()) st.pop();
                    if(st.size()!=0){
                        ans+=s[i];
                    }
                }
            }
        }
        return ans;
    }
};