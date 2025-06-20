class Solution {
public:
    long long  helper(vector<int> &piles,int val){
        long long count=0;
        for(int i=0;i<piles.size();i++){
            count+=(piles[i]/val);
            if(piles[i]%val!=0) count++;
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        for(int i=0;i<piles.size();i++){
            high=max(high,piles[i]);
        }
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long hours=helper(piles,mid);
            if(hours<=h){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};