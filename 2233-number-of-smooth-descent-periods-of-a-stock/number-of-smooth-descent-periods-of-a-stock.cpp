class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        long long  i=0;
        long long  j=0;
        long long ans=0;
        while(j<arr.size()){
            while(j<arr.size()-1 && arr[j]-1==arr[j+1]){
                j++;
            }
            long long len=j-i+1;
            long long count=(len*(len+1))/2;
            ans+=count;
            i=j+1;
            j=j+1;
        }
        return ans;
    }
};