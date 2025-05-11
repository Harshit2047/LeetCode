class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool flag=false;
        if(arr.size()<3) return false;
        int i=0;
        int j=0;
        while(j<arr.size()){
            while(j<arr.size() && arr[j]%2!=0){
                j++;
            }
            if(j-i+1>=4){
                flag=true;
                break;
            }
            i++;
            j=i;
        }
        return flag;
    }
};