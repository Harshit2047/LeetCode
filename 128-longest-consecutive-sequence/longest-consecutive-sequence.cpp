class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto i:nums){
            pq.push(i);
        }
        int count=0;
        int maxC=0;
        if(nums.size()==0) return 0;
        int num1=pq.top();
        pq.pop();
        while(pq.size()){
            int num2=pq.top();
            pq.pop();
            if(num2-num1==1) count++;
            else if((num2-num1)==0) count=count;
            else count=0;
            maxC=max(count,maxC);
            num1=num2;
        }
        return maxC+1;
    }

};