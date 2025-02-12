class Solution {
public:
    int maximumSum(vector<int>& nums) {
        if(nums.size()==1) return -1;
        priority_queue<pair<int, int>> pq;

        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int sum=0;
            while(num!=0){
                sum=sum+num%10;
                num=num/10;
            }
            pq.push({sum, nums[i]});
        }
        int maxAns=-1;
        pair<int,int> p;
        auto i=p;
        if(pq.size()!=0) {
            i=pq.top();
            pq.pop();
            }
        while(pq.size()){
            // auto i=pq.top();
            // pq.pop();
            // if(pq.size()==0) return maxAns;
            auto j=pq.top();
            pq.pop();
            if(i.first==j.first){
                maxAns=max(maxAns,i.second+j.second);
            }
            i=j;
        }
        return maxAns==0 ? -1:maxAns;
    
        
    }
};