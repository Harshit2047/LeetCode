class Solution {
public:
    int helper(int mid,vector<int> weights){
        int count=1;
        int wt=mid;
        for(auto i:weights){
            if(wt<i){
                count++;
                wt=mid;
                wt=wt-i;
            }
            else{
                wt=wt-i;
            }
        }
        return count;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int i=INT_MIN;
        for(auto x:weights) i=max(i,x);
        int j=0;
        for(auto i:weights) j+=i;
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            int count=helper(mid,weights);
            cout<<count<<" ";
            if(count>days){
                i=mid+1;
            }
            else{
                j=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
    }
};