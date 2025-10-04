class Solution {
public:
    int maxArea(vector<int>& height) {
        int low=0;
        int high=height.size()-1;
        int ans=0;
        while(low<high){
            int length=min(height[low],height[high]);
            int breath=high-low;
            ans=max(ans,length*breath);
            if(height[low]<height[high]) low++;
            else high--;
        }
        return ans;
    }
};