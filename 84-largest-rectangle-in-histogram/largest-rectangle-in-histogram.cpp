class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> nse(n);
        stack<int> st;
        st.push(n-1);
        nse[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.size()==0) nse[i]=n;
            else nse[i]=st.top();
               st.push(i);
        }

        // for(auto i:nse){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        while(st.size()){
            st.pop();
        }

        vector<int> pse(n);
        st.push(0);
        pse[0]=-1;
        for(int i=1;i<heights.size();i++){
            while(st.size() && heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.size()==0) pse[i]=-1;
            else pse[i]=st.top();
               st.push(i);
        }
        //  for(auto i:pse){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int ans=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int val=nse[i]-pse[i]-1;
            ans=max(ans,val*heights[i]);
        }
        return ans;

    }
};