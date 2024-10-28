class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> h(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());
        int max_count = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            int count = 1;
            long long current = nums[i];
            
            while (h.find(current * current) != h.end()) {
                current *= current;
                count++;
            }
            
            max_count = max(max_count, count);
        }
        
        return max_count > 1 ? max_count : -1;
    }
};
