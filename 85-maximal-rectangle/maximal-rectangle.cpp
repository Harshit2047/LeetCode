class Solution {
public:
    int healper(vector<int> heights){
        int n=heights.size();
        stack<int> st;
        st.push(n-1);
        vector<int> nsi(n);
        nsi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && heights[st.top()]>=heights[i]) st.pop();
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        vector<int> psi(n);
        psi[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size() && heights[st.top()]>heights[i]) st.pop();
            if(st.size()==0) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int width=nsi[i]-psi[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> temp(m,0);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') temp[j]=0;
                else temp[j]+=1;
            }
            ans=max(ans,healper(temp));
        }
    
        return ans;
    }
};