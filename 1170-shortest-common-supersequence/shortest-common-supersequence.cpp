class Solution {
public:
    
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length();
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int take=0;
                if(str1[i-1]==str2[j-1]) take=1+dp[i-1][j-1];
                int notTake=max(dp[i-1][j] , dp[i][j-1]);
                dp[i][j]=max(notTake,take);
            }
        }
        int i=n;
        int j=m;
        string LCS="";
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                LCS+=str1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(LCS.begin(),LCS.end());
        int x=0;
        int y=0;
        int z=0;
        string ans="";
         while( z<LCS.length()){
            while(str1[x]!=LCS[z]){
                ans+=str1[x];
                x++;
                
            }
            while(str2[y]!=LCS[z]){
                ans+=str2[y];
                y++;
                
            }

            ans=ans+LCS[z];
            x++;y++;z++;
            
         }
         while(x<n){
            ans+=str1[x];
            x++;
         }
         while(y<m){
            ans+=str2[y];
            y++;
         }
         return ans;
    }
};