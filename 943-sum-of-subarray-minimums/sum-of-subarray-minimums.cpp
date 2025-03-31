class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int s = arr.size();
        vector<int> pse(s);
        stack<int> st;
        st.push(0);
        pse[0] = -1;

        for (int i = 1; i < arr.size(); i++) {
            while (st.size() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (st.size() != 0) pse[i] = st.top();
            else pse[i] = -1;
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        vector<int> nxe(s);
        nxe[s - 1] = s;
        st.push(s - 1);

        for (int i = s - 2; i >= 0; i--) {
            while (st.size() && arr[st.top()] >= arr[i]) {  // Fix: Use `>=` to handle duplicates
                st.pop();
            }
            if (st.size() != 0) nxe[i] = st.top();
            else nxe[i] = s;
            st.push(i);
        }

        int ans = 0;
        int MOD = 1e9 + 7;  // Since the problem requires modulo operation

        for (int i = 0; i < arr.size(); i++) {
            int left = i - pse[i];
            int right = nxe[i] - i;
            ans = (ans + ((long long)left * right % MOD) * arr[i] % MOD) % MOD; // Fix contribution formula
        }

        return ans;
    }
};
