class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nge(n);
        stack<int> st;
        st.push(n-1);
        nge[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0) nge[i]=n;
            else nge[i]=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        vector<int> pge(n);
        pge[0]=-1;
        st.push(0);
        for(int i=1;i<n;i++){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0) pge[i]=-1;
            else pge[i]=st.top();
            st.push(i);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int width=nge[i]-pge[i]-1;
            ans=max(heights[i]*width,ans);
        }
        return ans;
    }
};