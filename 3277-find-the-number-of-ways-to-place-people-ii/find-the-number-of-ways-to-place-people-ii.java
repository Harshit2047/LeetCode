class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points,(a,b)->{
            if(a[0]!=b[0]) return Integer.compare(a[0],b[0]);
            else return Integer.compare(b[1],a[1]);
        });

        int n=points.length,count=0;
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            int miny=Integer.MAX_VALUE;
            for(int j=i-1;j>=0;j--){
                int x1=points[j][0],y2=points[j][1];
                if(y2<y) continue;
                if(y2<miny){
                    count++;
                    miny=y2;
                }

            }
        }
        return count;
    }
}