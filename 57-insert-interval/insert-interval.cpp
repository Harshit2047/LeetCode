class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size()==0){
            ans.push_back(newInterval);
            return ans;
        }
        int i=0;
        bool flag=true;
        if(intervals[0][0]<newInterval[0]){
            ans.push_back(intervals[0]);
            i++;
        }
        else{
            ans.push_back(newInterval);
            flag=false;
        }
        while(i<intervals.size()){
            int Ps=ans[ans.size()-1][0];
            int Pe=ans[ans.size()-1][1];
            if(intervals[i][0]<newInterval[0] || flag==false){
                if(Pe>=intervals[i][0]){
                    ans.pop_back();
                    ans.push_back({min(Ps,intervals[i][0]),max(Pe,intervals[i][1])});

                }
                else{
                    ans.push_back(intervals[i]);
                }
                i++;
                
            }
            else{
                   if(Pe>=newInterval[0]){
                    ans.pop_back();
                    ans.push_back({min(Ps,newInterval[0]),max(Pe,newInterval[1])});
                }
                else{
                    ans.push_back(newInterval);
                } 
                flag=false;
            }
        }
        if(flag==true){
            if(ans.size()){
                int Ps=ans[ans.size()-1][0];
                int Pe=ans[ans.size()-1][1];
                if(Pe>=newInterval[0]){
                    ans.pop_back();
                    ans.push_back({min(Ps,newInterval[0]),max(Pe,newInterval[1])});
                }
                else{
                    ans.push_back(newInterval);
                }
            }
        }
        return ans;
    }
};