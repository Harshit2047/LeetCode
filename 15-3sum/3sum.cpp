class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int count=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
           
            
                int val1=nums[i];
                int j=i+1;
                int k=nums.size()-1;
                while(j<k){
                    int sum=val1+nums[j]+nums[k];
                    if(sum==0){
                        vector<int> temp{val1,nums[j],nums[k]};
                        ans.push_back(temp);
                        while(i<nums.size()-2 && nums[i]==nums[i+1])i++;
                        while(j<k && nums[j]==nums[j+1])j++;
                        while(k>j && nums[k]==nums[k-1])k--;
                        j++;
                        k--;

                    }
                    else if(sum>0) k--;
                    else if(sum<0) j++;
                }
            
        }
        return ans;
    }
};