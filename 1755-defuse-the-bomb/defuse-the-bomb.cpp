class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> v;
        int n=code.size();
        if(k==0) return vector<int>(n,0);
        for(int i=0;i<code.size();i++){
            int j;
            if(k>=0) j=(i+1)%code.size();
            if(k<0)  j=(i-1+n)%code.size();
            int times=abs(k);
            int sum=0;
            while(times>0){
                int idx=(j+n)%code.size();
                cout<<idx<<" ";
                sum=sum+code[idx];
                if(k>=0)j++;
                if(k<0) j--;
                times--;
            }
            v.push_back(sum);    
        }
        return v;
    }
};