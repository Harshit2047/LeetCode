class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pqmax;
        for(int i = 0; i < nums.size(); i++) {
            pqmax.push(nums[i]);
        }        
        long long ans = 0; 
        while(k) {
            long long x = pqmax.top();
            pqmax.pop();
            ans = ans + x;
            

            x = ceil(static_cast<double>(x) / 3);
            cout << x << " ";
            pqmax.push(x);
            k--;
        }
        return ans;
    }
};
