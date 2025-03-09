class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int N=colors.size()+k-1;
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int i=0;
        int j=1;
        int ans=0;
        while(j<N){
            if(colors[j]==colors[j-1]){
                i=j;
            }
            if(j-i+1==k){
                ans+=1;
                i++;
            }
            j++;
        }
        return ans;
        

    }
};