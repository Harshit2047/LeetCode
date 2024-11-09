class Solution {
public:
    bool isPerfect(int n){
        int a=sqrt(n);
        return a*a==n;
    }
    int numSquares(int n) {
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            if(isPerfect(i)) v[i]=1;
            else{
                int m=INT_MAX;
                for(int j=1;j*j<=i;j++){
                    int a=v[j*j]+v[i-j*j];
                    m=min(m,a);
                }
                v[i]=m;
            }
        }
       
    return v[n];
    }
};