class Solution {
    public int findKthPositive(int[] arr, int k) {
        int sum=0,n=arr.length,ans=-1;
        sum+=(arr[0]-1);
        if(sum>=k) return k; 
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]>1){
               int x=arr[i]-arr[i-1]-1;
                if(sum+x>=k){
                    ans=arr[i-1]+(k-sum);
                    return ans;
                }
                sum+=x;
            }
        }
        if(sum<=k) ans=arr[n-1]+(k-sum);
        return ans;
    }
}