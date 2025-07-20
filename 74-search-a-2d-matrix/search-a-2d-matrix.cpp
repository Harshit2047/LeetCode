class Solution {
public:
    bool helper(vector<int> &v,int tar){
        int low=0;
        int high=v.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(v[mid]==tar){
                return true;
            }
            else if(v[mid]<tar){
                low=mid+1;
            }
            else high=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix[0].size()-1;
        int low=0;
        int high=matrix.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(matrix[mid][0]<=target && target<=matrix[mid][m]){
                return helper(matrix[mid],target);
            }
            else if(matrix[mid][0]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return false;
    }
};