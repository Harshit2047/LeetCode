class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>ans(boxes.size(),0);
        for(int i=0;i<boxes.size();i++){
            int countF=0;
            for(int j=i+1;j<boxes.size();j++){
                if(boxes[j]=='1'){
                    countF+=j-i;
                }
            }
             ans[i]+=countF;
             int countB=0;
             for(int j=i-1;j>=0;j--){
                if(boxes[j]=='1'){
                    countB+=i-j;
                }
            }
            ans[i]+=countB;


        }
        return ans;
    }
};