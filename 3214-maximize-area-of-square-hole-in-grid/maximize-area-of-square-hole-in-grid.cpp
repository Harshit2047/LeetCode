class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maximumVerticalSpace=1;
        int tempVertical=1;
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i+1]-vBars[i]==1){
                tempVertical++;
            }
            else tempVertical=1;
            maximumVerticalSpace=max(maximumVerticalSpace,tempVertical);
        }

        int maximumHorizontalSpace=1;
        int tempHorizontal=1;
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i+1]-hBars[i]==1){
                tempHorizontal++;
            }
            else tempHorizontal=1;
            maximumHorizontalSpace=max(maximumHorizontalSpace,tempHorizontal);
        }

        int side=min(maximumHorizontalSpace+1,maximumVerticalSpace+1);
        return side*side;
    }
};