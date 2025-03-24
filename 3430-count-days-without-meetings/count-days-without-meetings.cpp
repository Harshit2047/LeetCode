class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> v;
        int ans=0;
        v.push_back({meetings[0][0],meetings[0][1]});
        for(int i=1;i<meetings.size();i++){
            int size=v.size()-1;
            if(v[size][1]>=meetings[i][0]){
                int save1=v[size][0];
                int save2=v[size][1];
                v.pop_back();
                v.push_back({save1,max(meetings[i][1],save2)});
            }
            else{
                v.push_back({meetings[i][0],meetings[i][1]});
            }
        }
        for(int i=0;i<v.size();i++){
            ans+=v[i][1]-v[i][0]+1;
        }
        return days-ans;
    }
};