class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans1=-1;
        int ans2=-1;
        int idx1=(n+m-1)/2;
        int idx2=(n+m)/2;
        int i=0;
        int j=0;
        int count=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                if(count==idx1){
                    ans1=nums1[i];
                }
                if(count==idx2){
                    ans2=nums1[i];
                }
                i++;
            }
            else{
                 if(count==idx1){
                    ans1=nums2[j];
                }
                if(count==idx2){
                    ans2=nums2[j];
                }
                j++;
            }
            count++;
        }
        while(i<nums1.size()){
            if(count==idx1){
                ans1=nums1[i];
            }
            if(count==idx2){
                ans2=nums1[i];
            }
            i++;
            count++;
        }
        while(j<nums2.size()){
            if(count==idx1){
                ans1=nums2[j];
            }
            if(count==idx2){
                ans2=nums2[j];
            }
            j++;
            count++;
        }
        if((n+m)%2==0){
            return ((ans1+ans2)*1.0)/2;
        }
        else{
            return ans2;
        }
        
    }
};