class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int actualSize=nums.size();
        stack<int> st;
        for(int i=0;i<actualSize;i++){
            nums.push_back(nums[i]);
        }
        vector<int> nxt(nums.size());
        nxt[nxt.size()-1]=-1;
        st.push(nums[nums.size()-1]);
        for(int i=nums.size()-2;i>=0;i--){
            while(st.size() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.size()) nxt[i]=st.top();
            else nxt[i]=-1;
            st.push(nums[i]);
        }
        vector<int> ans(actualSize);
        for(int i=0;i<ans.size();i++){
            ans[i]=nxt[i];
        }
        
        return ans;
    }
};