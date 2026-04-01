class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // store indices and sort by positions
        vector<int> idx(n);
        for(int i = 0; i < n; i++) idx[i] = i;

        sort(idx.begin(), idx.end(), [&](int a, int b){
            return positions[a] < positions[b];
        });

        stack<int> st; // stores indices of robots moving right

        for(int id : idx){
            if(directions[id] == 'R'){
                st.push(id);
            } else {
                // current robot moving left
                while(!st.empty() && healths[id] > 0){
                    int top = st.top();

                    if(healths[top] < healths[id]){
                        st.pop();
                        healths[id]--;
                        healths[top] = 0;
                    }
                    else if(healths[top] > healths[id]){
                        healths[top]--;
                        healths[id] = 0;
                    }
                    else{
                        st.pop();
                        healths[top] = 0;
                        healths[id] = 0;
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};