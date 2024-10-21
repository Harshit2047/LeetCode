class Solution {
public:
   
    bool parseBoolExpr(string expression) {
        stack<char> st;
        unordered_set<char> s;
            for(int i=0;i<expression.size();i++){
                if(expression[i]!=')'){
                    st.push(expression[i]);
                }
                else{
                    while(st.size()>0 && st.top()!='('){
                        char c=st.top();
                        if(c=='f' || c=='t') s.insert(c);
                        st.pop();
                    }
                    st.pop();
                    
                    if(st.top()=='&'){
                        st.pop(); 
                        if(s.find('f')!=s.end()) st.push('f');
                        else st.push('t');
                    }
                    if(st.top()=='|'){
                        st.pop(); 
                        if(s.find('t')!=s.end()) st.push('t');
                        else st.push('f');
                    }
                    if(st.top()=='!'){
                        st.pop(); 
                        if(s.find('t')!=s.end()) st.push('f');
                        if(s.find('f')!=s.end()) st.push('t');
                    }
                    s.clear();
                      
                }
            }

        return st.top()=='t';
    }
};