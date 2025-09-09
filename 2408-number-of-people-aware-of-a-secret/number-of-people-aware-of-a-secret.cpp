class Solution {
public:
    int mod=1000000007;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int,int>> q;
        q.push({1,1});
        for(int i=2;i<=n;i++){
            int size=q.size();
            long long count=0;
            while(size--){
                int num=q.front().first;
                int days=q.front().second;
                q.pop();
                if(days>=forget) continue;
                if(days>=delay){
                    count=(count+num)%mod;
                }
                q.push({num,days+1});
            }
            q.push({count,1});
        }
        long long  ans=0;
        while(q.size()){
            int count=q.front().first;
            ans=(ans+count)%mod;
            q.pop();
        }
        return (int)ans;
    }
};