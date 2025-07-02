class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int preSum=0;
        int arrSum=0;
        int val=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            arrSum+=arr[i];
            preSum+=val;
            val++;
            if(arrSum==preSum) count++;
        }
        return count;
    }
};