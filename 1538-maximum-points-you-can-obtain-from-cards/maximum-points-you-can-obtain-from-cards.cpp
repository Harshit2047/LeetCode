class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int sum=0;
        int ans=0;
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int i=k-1;
        int j=arr.size()-1;
        ans=max(ans,sum);
        while(i>=0){
            sum-=arr[i];
            sum+=arr[j];
            i--;
            j--;
            
            ans=max(ans,sum);
            
        }
        
        return ans;
    }
};