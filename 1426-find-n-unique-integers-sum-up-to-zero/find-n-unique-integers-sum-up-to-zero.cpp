class Solution {
public:
    vector<int> sumZero(int n) {
            vector<int> v;
            int val=-1;
            if(n%2==0){
                for(int i=0;i<n/2;i++){
                    v.push_back(val--);
                }
                for(int i=0;i<n/2;i++){
                    v.push_back(-v[i]);
                }
            }else{
                for(int i=0;i<n/2;i++){
                    v.push_back(val--);
                }
                v.push_back(0);
                for(int i=0;i<n/2;i++){
                    v.push_back(-v[i]);
                }
            }
            return v;
    }
};