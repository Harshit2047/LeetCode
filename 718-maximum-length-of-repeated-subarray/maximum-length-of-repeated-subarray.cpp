class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=INT_MIN;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    int p1=i;
                    int p2=j;
                    int count=0;
                    while(p1<nums1.size() && p2<nums2.size()){
                        if(nums1[p1++]==nums2[p2++]) count++;
                        else break;
                        
                    }
                    ans=max(ans,count);
                }
            }
        }
        return ans==INT_MIN ? 0 : ans;
    }
};