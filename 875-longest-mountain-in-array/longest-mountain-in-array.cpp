class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        for(int i=1;i<arr.size()-1;i++){
            int left=i;
            int right=i;
            while(left>0 && arr[left-1]<arr[left])left--;
            while(right<arr.size()-1 && arr[right]>arr[right+1]) right++;
            int size=  (left!=i && right!= i ) ? (right-left+1):0;
            ans=max(ans,size);
        }
        return ans;
    }
};