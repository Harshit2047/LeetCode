class Solution {
public:
    int helper(vector<int> &v){
        
        int n=v.size();
        vector<int> nsi(n);
        vector<int> psi(n);
        nsi[n-1]=n;
        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(st.size() && (v[st.top()])>=v[i]){
                st.pop();
            }
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        psi[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.size()==0) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int breath=nsi[i]-psi[i]-1;
            int hight=v[i];
             ans=max(ans,breath*hight);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix.size();j++){
                if(j==0) v[j][i]=matrix[j][i]-'0';
                else{
                    if(matrix[j][i]-'0'==0) v[j][i]=0;
                    else v[j][i]=v[j-1][i]+matrix[j][i]-'0';
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,helper(v[i]));
        }
        return ans;
        
    }
};