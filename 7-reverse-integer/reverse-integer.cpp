class Solution {
public:
    int reverse(int x) {
        int temp=x;
        long number=0;
        while(temp){
            int n=temp%10;
            number=10*number+n;
            temp=temp/10;
        }
        return number>INT_MAX ||number<INT_MIN ? 0:number;
        
    }
};