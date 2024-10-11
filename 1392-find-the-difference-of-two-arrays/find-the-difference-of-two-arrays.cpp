class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        
        for(int i=0;i<nums1.size();i++){
            st1.insert(nums1[i]);
        }

        for(int i=0;i<nums2.size();i++){
            st2.insert(nums2[i]);
        }

        vector<vector<int>> ans;
        vector<int> v1;
        vector<int> v2;
        for(auto i : st1){
            if(st2.find(i)==st2.end()) v1.push_back(i);
        }

        for(auto i : st2){
            if(st1.find(i)==st1.end()) v2.push_back(i);
        }

        ans.push_back(v1);
        ans.push_back(v2);

        return ans;

        
    }
};