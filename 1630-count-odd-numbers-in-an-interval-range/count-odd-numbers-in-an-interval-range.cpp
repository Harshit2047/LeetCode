class Solution {
public:
    int countOdds(int low, int high) {
        if(high-low == 0 ){
            if(high%2!=0) return 1;
            else return 0;
        }
        if(low%2==0 && high%2==0){
            return (high-low-1)/2+1;
        }
        else if(low%2!=0 && high%2!=0){
            return (high-low-1)/2+2;
        }
        else return (high-low-1)/2+1;
    }
};