class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        deque<int> dq;
        vector<int> ans;
        while(j<nums.size()){
            while(dq.size() && nums[dq.back()]<nums[j]) dq.pop_back();
                dq.push_back(j);
            if(j-i+1==k){
                ans.push_back(nums[dq.front()]);
                i++;
                if( dq.size() &&dq.front()<i ) dq.pop_front();
            }
            j++;
        }
        return ans;
    }
};