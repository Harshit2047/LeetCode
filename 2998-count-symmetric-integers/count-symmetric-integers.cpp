class Solution {
public:
    bool helper(string s){
        int i=0;
        int j=s.length()-1;
        int sumR=0;
        int sumL=0;
        while(i<j){
            sumR=sumR+(s[i]-'0');
            sumL=sumL+(s[j]-'0');
            i++;
            j--;
        }
        if(sumR==sumL) return true;
        else return false;
    }
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            if(s.length()%2==0){
                if(helper(s)) count++;
            }
        }
        return count;
    }
};