class Solution {
public:
    void helper(vector<int>& candidates,int idx,int target,vector<int> temp,vector<vector<int>> &ans){
        if(target<0 || idx==candidates.size()) return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        helper(candidates,idx+1,target,temp,ans);
        temp.push_back(candidates[idx]);
        helper(candidates,idx,target-candidates[idx],temp,ans);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates,0,target,temp,ans);
        return ans;
    }
};