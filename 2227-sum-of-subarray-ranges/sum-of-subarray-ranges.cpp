class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        vector<int> nsi(n);
        stack<int> st;
        st.push(n-1);
        nsi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.size()==0)nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        vector<int> psi(n);
        st.push(0);
        psi[0]=-1;
        for(int i=1;i<n;i++){
            while(st.size() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.size()==0) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
         while(st.size()){
            st.pop();
        }
        vector<int> ngi(n);
        st.push(n-1);
        ngi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i]=n;
            else ngi[i]=st.top();
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        vector<int> pgi(n);
        st.push(0);
        pgi[0]=-1;
        for(int i=1;i<n;i++){
            while(st.size() && nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.size()==0) pgi[i]=-1;
            else pgi[i]=st.top();
            st.push(i);
        }
    
    long long ans=0;
    for(int i=0;i<nums.size();i++){
        int leftS=i-psi[i];
        int rightS=nsi[i]-i;
        int leftG=i-pgi[i];
        int rightG=ngi[i]-i;
        ans+=(1LL*(rightG*leftG)*nums[i])-(1LL*(leftS*rightS)*nums[i]);
    }
    return ans;
    }
};