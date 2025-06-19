class Solution {
public:
    int findMin(vector<int>& arr) {
        if(arr.size()==1) return arr[0];
        int low=0;
        int high=arr.size()-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                ans=min(ans,arr[low]);
                low++;
                high--;
            }
            else if(arr[low]<=arr[mid]){
                ans=min(ans,arr[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,arr[mid]);
                high=mid-1;
            }
        }
        return ans;
    }
};