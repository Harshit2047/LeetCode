class Solution {
public:
    bool isPowerOfThree(int x) {
        if(x==1) return true;
        if(x<=0 || x%3!=0) return false;
        return isPowerOfThree(x/3);
    }
};