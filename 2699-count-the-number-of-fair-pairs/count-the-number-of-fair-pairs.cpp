class Solution {
public:
    int lower_bound(vector<int> &nums, int val, int start) {
    int low = start, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < val) low = mid + 1;
        else high = mid;
    }
    return low;
}

int upper_bound(vector<int> &nums, int val, int start) {
    int low = start, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= val) low = mid + 1;
        else high = mid;
    }
    return low;
}

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int maxNumL=lower-nums[i];
            int idxL=lower_bound(nums,maxNumL,i+1);
            int npairL=idxL-i-1;
            int maxNumU=upper-nums[i];
            int idxU=upper_bound(nums,maxNumU,i+1);
            int npairU=idxU-i-1;
            ans+=npairU-npairL;
        }
        return ans;
    }
};