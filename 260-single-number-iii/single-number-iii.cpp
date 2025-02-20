class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int XOR=0;
        for(auto i:nums){
            XOR=XOR^i;
        }
       int mask = XOR & (-(unsigned int)XOR); // diffrent bit

        int ans1=0;
        int ans2=0;
        for(auto i:nums){
            if((mask&i)==0) ans1^=i;
            else if((mask&i)!=0) ans2^=i;
        }
        return {ans2,ans1};
    }
};