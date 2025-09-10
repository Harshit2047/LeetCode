class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v(n+1,true);
        int count=0;
        for(int i=2;i<n;i++){
            if(v[i]==true) {
                count++;
                for(int j=i*2;j<n;j=j+i){
                    v[j]=false;
                }
            }
        }
        return count;
    }
};