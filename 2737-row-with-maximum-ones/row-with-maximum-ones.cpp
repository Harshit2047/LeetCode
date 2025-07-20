class Solution {
public:
    int helper(vector<int> v){
        int low=0;
        int high=v.size()-1;
        sort(v.begin(),v.end());
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==1){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans==-1 ? 0 : v.size()-ans;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n=mat.size();
        int Count=INT_MIN;
        int idx=-1;
        for(int i=0;i<n;i++){
           int temp= helper(mat[i]);
            if(temp>Count){
                idx=i;
                Count=temp;
            }
        }
        return {idx,Count};
    }
};