class Solution {
public:
    double helper(vector<int> &p1,vector<int> &p2,vector<int> &p3){
        return 0.5*abs(p1[0]*(p2[1]-p3[1])+p2[0]*(p3[1]-p1[1])+p3[0]*(p1[1]-p2[1]));

    }
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans=0;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    ans=max(ans,helper(points[i],points[j],points[k]));
                }
            }
        }
        return ans;
    }
};