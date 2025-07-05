class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freq(500+1,0);
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        int ans=-1;
        for(int i=1;i<freq.size();i++){
            if(freq[i]==i){
                ans=freq[i];
            }
        }
        return ans;
        
    }
};