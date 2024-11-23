class Solution {
    public boolean canAliceWin(int n) {
        if(n<10) return false;
        int num=10;
        int count=0;
        while(n>=num){
            n=n-num;
            num--;
            count++;
        } 
        if(count%2==0) return false;
        else return true;
    }
}