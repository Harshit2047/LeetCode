class Solution {
public:
    int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> nsi(n);
        vector<int> psi(n);
        stack<int> st;
        st.push(n-1);
        nsi[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(st.size() && arr[st.top()]>=arr[i]) st.pop();
            if(st.size()==0) nsi[i]=n;
            else nsi[i]=st.top();
            st.push(i);
        }
        while(st.size()) st.pop();
        st.push(0);
        psi[0]=-1;
        for(int i=1;i<n;i++){
            while(st.size() && arr[st.top()]>arr[i]) st.pop();
            if(st.size()==0) psi[i]=-1;
            else psi[i]=st.top();
            st.push(i);
        }
        int  ans=0;
        for(int i=0;i<n;i++){
            long long left=i-psi[i];
            long long right=nsi[i]-i;
            ans = (ans + (left * right % MOD) * arr[i] % MOD) % MOD;

        }
        return ans;
    }
};