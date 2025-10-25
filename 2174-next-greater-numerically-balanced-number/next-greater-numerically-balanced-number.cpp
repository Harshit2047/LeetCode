class Solution {
public:
    bool helper(int n){
        vector<int> v(10,0);
        while(n){
            v[n%10]++;
            n=n/10;
        }
        for(int i=0;i<10;i++){
            if(v[i]!=0 && v[i]!=i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;;i++){
            if(helper(i)) return i;
        }
        return -1;
    }
};