class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int carry=0;
        int i=n-1;
        while(i>=0){
            int num=(i==n-1) ? 1+digits[i]+carry:digits[i]+carry ;
            digits[i]=num%10;
            num=num/10;
            carry=num;
            i--;
        }
        if(carry!=0) digits.insert(digits.begin(), carry);
        return digits;
    }
};