class Solution {
public:
    bool isPalindrome(int x) {
        long rev=0;
        int temp=x;
        while(temp){
            rev=10*rev+temp%10;
            temp=temp/10;
        }
        if(x<0) return false;
        return rev==x;
        
    }
};