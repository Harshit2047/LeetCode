class Solution {
public:
    void helper(vector<int> &v,int &ans){
       
        int n=v.size();
        vector<int> nse(n);
        stack<int> st;
        st.push(n-1);
        nse[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.size()==0) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }

        while(st.size()){
            st.pop();
        }
        st.push(0);
        vector<int> pse(n);
        pse[0]=-1;
        for(int i=1;i<n;i++){
            while(st.size() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(st.size()==0) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        
        for(int i=0;i<v.size();i++){
            ans=max(ans,((nse[i]-pse[i]-1)*v[i]));
        }
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       if (matrix.empty() || matrix[0].empty()) return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> v(rows, vector<int>(cols));
        for (int j = 0; j < cols; j++) {
            v[0][j] = (matrix[0][j] == '1') ? 1 : 0;
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                v[i][j] = (matrix[i][j] == '0') ? 0 : v[i - 1][j] + 1;
            }
        }
        int A=0;
        for(int i=0;i<matrix.size();i++){
            int ans=0;
            helper(v[i],ans);
            A=max(A,ans);
        }
        
        return A;
    }
};