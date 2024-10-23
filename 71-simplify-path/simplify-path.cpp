class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                continue;
            }
            else{
                string s="";
                while(i<path.length() && path[i]!='/'){
                    s=s+path[i++];
                }
            cout<<s<<" ";
                if(s==".") continue;
                else if(s=="..") {
                    if(st.size()){
                        st.pop();
                    }
                }
                
                else  st.push(s);
                
            }
        }
        string ans="";
        while(st.size()){
            
            ans='/'+st.top()+ans;
            st.pop();
        }
        if(ans.size()==0) return "/";
        return ans;
    }
};
