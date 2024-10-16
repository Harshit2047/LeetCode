class Solution {
public:
    static bool comp(vector<int> &v1 ,vector<int> &v2){
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int n=ans.size()-1;
            vector<int> v=ans.back();
            if(intervals[i][0]<=v[1]){
                ans[n][0]=min(intervals[i][0],v[0]);
                ans[n][1]=max(intervals[i][1],v[1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};