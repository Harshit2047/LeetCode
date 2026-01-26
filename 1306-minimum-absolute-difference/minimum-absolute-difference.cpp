class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        int diff=INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            diff=min(diff,arr[i+1]-arr[i]);
        }
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-arr[i]==diff){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};