class Solution {
    long helper(int[]coins,int idx,int amount,long[][]dp){
        if(idx==coins.length){
            if(amount==0) return 0;
            else return Integer.MAX_VALUE;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        long take=Integer.MAX_VALUE;
       if(amount-coins[idx]>=0) take=1+helper(coins,idx,amount-coins[idx],dp);
        long skip=helper(coins,idx+1,amount,dp);
        return dp[idx][amount]=Math.min(take,skip);
    }
    public int coinChange(int[] coins, int amount) {
        long [][]dp=new long[coins.length][amount+1];
        for(int i=0;i<coins.length;i++){
        for(int j=0;j<amount+1;j++){
            dp[i][j]=-1;
        }
       }
       int x= (int)helper(coins,0,amount,dp);
       
       
       if(x>=Integer.MAX_VALUE) return -1;
       else return x;
    }
}