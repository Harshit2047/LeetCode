class Solution {
public:
    void helper(vector<vector<int>> &finalans,vector<int> ans,vector<bool> isVisited,vector<int> &nums){
        if(ans.size()==nums.size()){
            finalans.push_back(ans);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(isVisited[i]==false){
                ans.push_back(nums[i]);
                isVisited[i]=true;
                helper(finalans,ans,isVisited,nums);
                isVisited[i]=false;
                ans.pop_back();

            } 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalans;
        vector<int> ans;
        vector<bool> isVisited(nums.size(),false);
        helper(finalans,ans,isVisited,nums);
        return finalans;
        
    }
};