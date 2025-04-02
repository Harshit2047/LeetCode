class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.size()==0 && s[i]!='0'){
                st.push(s[i]);
            }
            else{
                while(st.size() && k!=0 && st.top()>s[i]){
                    st.pop();
                    k--;
                }
                if(st.size() == 0 && s[i]=='0') continue;
                st.push(s[i]);
            }
        }
        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       
        if(ans.length()==0) return "0";
        if(ans.length()<=k) return "0";
        if(k!=0) return ans.substr(0,ans.length()-k);
        return ans;
    }
};