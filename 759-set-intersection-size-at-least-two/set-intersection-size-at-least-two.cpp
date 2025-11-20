struct cmp{
    bool operator()(const vector<int> v1,const vector<int> v2){
        if(v1[1]==v2[1]) return v1[0]>v2[0];
        return v1[1]<v2[1];
    }
};
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp());
        int first=intervals[0][1]-1;
        int second=intervals[0][1];
        int ans=2;
        for(int i=1;i<intervals.size();i++){
            if(first>=intervals[i][0]) continue;
            else if(second>=intervals[i][0]){
                ans+=1;
                first=second;
                second=intervals[i][1];
            }
            else {
                    ans+=2;
                   first=intervals[i][1]-1;
                    second=intervals[i][1];
            }
        }
        return ans;
    }
};