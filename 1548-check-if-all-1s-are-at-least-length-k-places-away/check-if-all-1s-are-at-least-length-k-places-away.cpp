class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int i=0;
        while(i<nums.size() && nums[i]!=1)i++;
        int j=i+1;
        bool ans=true;
        while(j<nums.size()){
            while(j<nums.size() && nums[j]!=1) j++;
            cout<<j-i-1<<endl;
            if(j<nums.size() && j-i-1 <k){
                ans=false;
                break;
            }
            i=j;
            j+=1;
        }
        return ans;
    }
};