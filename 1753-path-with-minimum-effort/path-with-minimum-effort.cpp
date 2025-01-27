class Solution {
public:
    struct compare{
        bool operator()(const vector<int> &a,const vector<int> &b){
            if(a[2]==b[2]) return a[0]>b[0];
            return a[2]>b[2];
        }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<int>> costArr(heights.size(),vector<int>(heights[0].size(),INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,compare> pq;
        costArr[0][0]=0;
        pq.push({0,0,0});
        while(pq.size()){
            vector<int> temp=pq.top();
            pq.pop();
            int i=temp[0];
            int j=temp[1];
            int diff=temp[2];
            for(int x=0;x<dir.size();x++){
                int i_=i+dir[x][0];
                int j_=j+dir[x][1];

                if (i_ >= 0 && i_ < heights.size() && j_ >= 0 && j_ < heights[0].size()){
                    int currDiff=abs(heights[i_][j_]-heights[i][j]);
                    int val=max(diff,currDiff);
                    if(costArr[i_][j_]>val){
                        costArr[i_][j_]=val;
                        pq.push({i_,j_,costArr[i_][j_]});
                    }

                }
            }
        }
        
        return costArr[heights.size()-1][heights[0].size()-1];
    }
};