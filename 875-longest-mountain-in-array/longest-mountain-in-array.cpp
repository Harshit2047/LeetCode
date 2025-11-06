class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans=0;
        int n=arr.size();
        vector<int> inc(n,0);
        vector<int> dec(n,0);
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i]) inc[i]=inc[i-1]+1;
            else inc[i]=0;
        }
        for(int i=arr.size()-2;i>=0;i--){
            if(arr[i+1]<arr[i]) dec[i]=dec[i+1]+1;
            else dec[i]=0;
        }
        for(int i=0;i<n;i++){
            if(inc[i]!=0 && dec[i]!=0) ans=max(ans,inc[i]+dec[i]+1);
        }
        return ans;
    }
};