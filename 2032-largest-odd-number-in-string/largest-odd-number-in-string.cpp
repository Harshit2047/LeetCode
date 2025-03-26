class Solution {
public:
    string largestOddNumber(string num) {
        int save=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                save=i;
                break;
            }
        }
        if(save==-1) return "";
        return num.substr(0,save+1);
    }
};