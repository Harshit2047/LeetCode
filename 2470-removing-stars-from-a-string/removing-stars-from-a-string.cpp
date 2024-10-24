class Solution {
public:
    string removeStars(string s) {

        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]!='*') st.push(s[i]);
            else{
                if(st.size()) st.pop();
            }
        }
        string ans="";
        while(st.size()){
            ans +=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};