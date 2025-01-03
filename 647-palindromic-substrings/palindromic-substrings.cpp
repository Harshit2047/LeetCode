class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
        int count=0;
        for(int k=0;k<dp.size();k++){
            int j=k;  int i=0;
            while(j<dp.size()){
                if(i==j){
                    dp[i][j]=1;
                    count++;
                }
                else if(i==j-1){
                    if(s[i]==s[j]){
                        count++;
                        dp[i][j]=1;
                    }
                }
                else{
                    if(s[i]==s[j]){
                        if(dp[i+1][j-1]==1){
                            count++;
                            dp[i][j]=1;
                        }
                    }
                }
                j++;
                i++;
            }
        }
        return count;
    }
};