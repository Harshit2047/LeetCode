class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                swap(arr[i][j], arr[j][i]);
            }
        }

        for(int i =0;i<arr.size();i++){
            reverse(arr[i].begin(),arr[i].end());
        }
    }
};