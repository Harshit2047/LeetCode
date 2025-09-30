class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> temp(n-i,0);
            v.push_back(temp);
        }
        for(int i=0;i<n;i++){
            v[0][i]=nums[i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<v[i].size();j++){
                v[i][j]=(v[i-1][j]+v[i-1][j+1])%10;
            }
        }
        return v[n-1][0];
    }
};