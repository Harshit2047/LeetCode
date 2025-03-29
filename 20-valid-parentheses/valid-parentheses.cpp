class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') st.push(s[i]);
            else{
                if(s[i]==')' && st.size() && st.top()=='(') st.pop();
                else if(s[i]==']' && st.size() && st.top()=='[') st.pop();
                else if(s[i]=='}' && st.size() && st.top()=='{') st.pop();
                else return false;
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};