class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(st.size()==0 || k==0){
                st.push(num[i]);
            }
            else{
                while(st.size() && st.top()>num[i] && k>0){
                    k--;
                    st.pop();
                }
                st.push(num[i]);
            }
            if(st.size()==1 && st.top()=='0') st.pop();
            
        }
        while(k && st.size()){
            st.pop();
            k--;
        }

        string ans="";
        while(st.size()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==0) return "0";
        return ans;
    }
};