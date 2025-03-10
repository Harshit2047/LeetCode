class Solution {
public:
    void helper(vector<int> &nums,vector<vector<int>> &finalans,int idx,vector<int> ans){
        if(idx==nums.size()){
            finalans.push_back(ans);
            return;
        } 
        helper(nums,finalans,idx+1,ans);
        ans.push_back(nums[idx]);
        helper(nums,finalans,idx+1,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalans;
        vector<int> ans;
        helper(nums,finalans,0,ans);
        return finalans;
    }
};