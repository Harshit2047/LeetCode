class Solution {
public:
    int shipWithinDays(vector<int>& weights, int th) {
         int i = *max_element(weights.begin(), weights.end());
        int j=0;
        int ans=-1;
        for(auto i:weights) j+=i;
        while(i<=j){
            int mid=i+(j-i)/2;
            int wt=mid;
            int days=1;
            for (int k = 0; k < weights.size(); k++) {
                if (wt < weights[k]) { 
                    days++;
                    wt = mid;
                }
                wt -= weights[k]; 
            }
            if(days<=th){
                ans=mid;
                j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};