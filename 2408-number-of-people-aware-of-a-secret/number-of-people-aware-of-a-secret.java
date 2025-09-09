class Pair{
    long p;
    long d;
    Pair(long p,long d){
        this.p=p;
        this.d=d;
    }
}
class Solution {
    public int peopleAwareOfSecret(int n, int delay, int forget) {
        Queue<Pair>q=new LinkedList<>();
        q.add(new Pair(1,1));
        final int MOD=1000000007;
        for(int i=2;i<=n;i++){
            int size=q.size();
            long c=0;
            for(int j=0;j<size;j++){
                Pair p=q.remove();
                if(p.d<forget && p.d>=delay){
                    c=(c+p.p)%MOD;
                     if(p.d<forget) q.add(new Pair(p.p,p.d+1));
                }
                else if(p.d<forget){
                    q.add(new Pair(p.p,p.d+1));
                }
            }
           if(c>0) q.add(new Pair(c,1));
        }
        long sum=0;
        while(q.size()>0){
            Pair p=q.remove();
             sum=(sum+p.p)%MOD;
            // if(p.d<forget) sum=((sum%1000000007)+(p.p%1000000007))%1000000007;
        }
        return (int)sum;
    }
}