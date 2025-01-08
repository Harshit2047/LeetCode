class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>SLIS(nums.size(),0);
        vector<int>ELIS(nums.size(),0);

        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    SLIS[i]=max(SLIS[j],SLIS[i]);
                }
            }
            SLIS[i]+=1;
        }
    for(auto i:SLIS){
        cout<<i<<" ";
    }
cout<<endl;
         for(int i=nums.size()-1;i>=0;i--){
            for(int j=nums.size()-1;j>i;j--){
                if(nums[i]>nums[j]){
                    ELIS[i]=max(ELIS[j],ELIS[i]);
                }
            }
            ELIS[i]+=1;
        }
        for(auto i:ELIS){
        cout<<i<<" ";
    }

        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int temp=INT_MIN;
            if(SLIS[i]!=1 && ELIS[i]!=1){
                temp=(SLIS[i]+ELIS[i]-1);
                }
            ans=max(ans,temp);
        }
        if(ans==INT_MIN) return 0;
        return nums.size()-ans;
    }
};