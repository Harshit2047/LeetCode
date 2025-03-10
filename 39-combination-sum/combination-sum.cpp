class Solution {
public:
    void helper(vector<int> &arr,int target,int idx,vector<int> ans,vector<vector<int>> &finalans){
        
            if(target==0){
                finalans.push_back(ans);
                return;
            } 
            if(idx>=arr.size() || target<0){
                return;
            }
        
            helper(arr,target,idx+1,ans,finalans);
            ans.push_back(arr[idx]);
            helper(arr,target-arr[idx],idx,ans,finalans);
       
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> finalans;
        vector<int> ans;
        helper(arr,target,0,ans,finalans);
        return finalans;
    }
};