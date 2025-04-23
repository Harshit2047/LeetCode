class Solution {
public:
    int sum(int n){
        int s=0;
        while(n){
            int last=n%10;
            s+=last;
            n=n/10;
        }
        return s;
    }
    int countLargestGroup(int n) {
        vector<int> v(n+1);
        for(int i=1;i<=n;i++){
            int temp=sum(i);
            v[temp]++;
        }
        int mini=INT_MIN;
        for(int i=1;i<v.size();i++){
            mini=max(v[i],mini);
        }
        int count=0;
        for(int i=1;i<v.size();i++){
            if(v[i]==mini) count++;
        }
        return count;

        
    }
};