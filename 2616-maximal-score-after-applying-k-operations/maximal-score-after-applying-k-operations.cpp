class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if(pq.size() > k) pq.pop();
        }
        
        priority_queue<int> pqmax;
    
        while(pq.size()) {
            pqmax.push(pq.top());
            pq.pop();
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
