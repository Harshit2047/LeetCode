class Solution {
public:
    double helper(double x, long long n){
        if(n==1) return x;
        if(n%2!=0){
            return x* pow(helper(x,n/2),2);
        }
        else return pow(helper(x,n/2),2);
    }
    double myPow(double x, int n) {
        long long N =n;
        if(N==0) return 1;
        if(x==1) return 1;
        double ans= helper(x,abs(N));
        if(N<0) return 1/ans;
        else return ans;
        
    }
};