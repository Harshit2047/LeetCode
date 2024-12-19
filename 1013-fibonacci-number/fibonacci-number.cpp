class Solution {
public:

    int fibo(int n,vector<int> &arr){
        if(n<=1) return n;
        if(arr[n]!=0) return arr[n];
        int ans=fibo(n-1,arr)+fibo(n-2,arr);
        arr[n]=ans;
        return ans;

    }
    int fib(int n) {
        vector<int> arr(n+1,0);
         return fibo(n,arr);         
    }
};