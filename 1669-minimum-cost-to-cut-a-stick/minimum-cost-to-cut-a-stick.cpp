class Solution {
public:
    int helper(int i,int j,vector<int> &arr,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int m=INT_MAX;
        for(int k=i;k<=j;k++){
            int len=arr[j+1]-arr[i-1];
            int cost=helper(i,k-1,arr,dp)+helper(k+1,j,arr,dp)+len;
            m=min(cost,m);
        }
        return dp[i][j]=m;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<int> Mycuts(cuts.size()+2);
        Mycuts[0]=0;
        Mycuts[Mycuts.size()-1]=n;
        for(int i=1;i<Mycuts.size()-1;i++){
            Mycuts[i]=cuts[i-1];
        }
        vector<vector<int>> dp(Mycuts.size()+1,vector<int>(Mycuts.size()+1,-1));
        return helper(1,Mycuts.size()-2,Mycuts,dp);
    }
};