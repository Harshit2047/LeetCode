class Solution {
public:
    int GCD(int prev,int next){
        if(next==0) return prev;
        return GCD(next,prev%next);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        for(auto i:nums){
            while(ans.size()){
                int prev=ans.back();
                int cur=i;
                int gcd=GCD(prev,cur);
                if(gcd<=1) break;
                ans.pop_back();
                i=prev/gcd*cur;
            }
            ans.push_back(i);
        }
        return ans;
    }
};