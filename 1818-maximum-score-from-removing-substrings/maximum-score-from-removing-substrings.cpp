class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;
        int ans = 0;

        // Decide the order based on the higher score
        char first = 'a', second = 'b';
        int firstScore = x, secondScore = y;
        
        if (y > x) {
            swap(first, second);
            swap(firstScore, secondScore);
        }

        // Remove higher-scoring pairs first
        for (char ch : s) {
            if (!st.empty() && ch == second && st.top() == first) {
                ans += firstScore;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        // Process remaining characters for the lower-scoring pairs
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

        for (char ch : remaining) {
            if (!st.empty() && ch == first && st.top() == second) {
                ans += secondScore;
                st.pop();
            } else {
                st.push(ch);
            }
        }

        return ans;
    }
};
