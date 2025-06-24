class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> NGE(n);
        vector<int> PGE(n);
        int temp=INT_MIN;
        for(int i=0;i<n;i++){
            temp=max(temp,height[i]);
            PGE[i]=temp;
        }
        temp=INT_MIN;
        for(int i=n-1;i>=0;i--){
            temp=max(temp,height[i]);
            NGE[i]=temp;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int minVal=min(PGE[i],NGE[i]);
            ans+=minVal-height[i];
        }
        return ans;
    }
};