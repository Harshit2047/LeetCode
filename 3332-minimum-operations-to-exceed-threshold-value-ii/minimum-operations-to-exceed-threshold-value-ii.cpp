class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int count=0;
        while(pq.size()){
            if(pq.top()>=k) break;
            long long num1=pq.top();
            pq.pop();
            if(pq.size()==0) break;
            long long num2=pq.top();
            pq.pop();
            long long temp=min(num1,num2)*2+max(num1,num2);
            pq.push(temp);
            count++;

        }
        return count;

    }
};