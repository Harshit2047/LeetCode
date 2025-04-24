class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
       unordered_set<int> st;
       for(auto i:nums){
        st.insert(i);
       } 
       int size=st.size();
       int i=0;
       int j=0;
       unordered_map<int,int> mp;
       int ans=0;
       while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()==size){
                ans+=nums.size()-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
                
            }
            j++;
       }
       return ans;
    }
};