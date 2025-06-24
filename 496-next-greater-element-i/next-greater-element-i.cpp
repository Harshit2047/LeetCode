class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n=nums2.size();
        st.push(nums2[n-1]);
        vector<int> ans(n);
        ans[n-1]=-1;
        for(int i=n-2;i>=0;i--){
            while(st.size() && nums2[i]>st.top()){
                st.pop();
            }
            if(st.size()==0) ans[i]=-1;
            else ans[i]=st.top();
            st.push(nums2[i]);
        }
        int m=nums1.size();
        vector<int> A;
        for(int i=0;i<nums1.size();i++){
            int val=nums1[i];
            for(int j=0;j<n;j++){
                if(val==nums2[j]){
                    A.push_back(ans[j]);
                }
            }
        }
        return A;
    }
};