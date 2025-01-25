class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        vector<int> sortedV = nums;
        sort(sortedV.begin(), sortedV.end());


        int groupNumber = 0;
        unordered_map<int, list<int>> groupAndNums; 
        unordered_map<int, int> elementToGroup;    

  
        groupAndNums[groupNumber].push_back(sortedV[0]);
        elementToGroup[sortedV[0]] = groupNumber;

        for (int i = 1; i < sortedV.size(); i++) {
            if (abs(sortedV[i] - sortedV[i - 1]) > limit) {
                groupNumber++; 
            }
            groupAndNums[groupNumber].push_back(sortedV[i]);
            elementToGroup[sortedV[i]] = groupNumber; 
        }

       
        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = elementToGroup[num]; 
            ans[i] = *(groupAndNums[group].begin()); 
            groupAndNums[group].pop_front(); 
        }

        return ans;
    }
};
