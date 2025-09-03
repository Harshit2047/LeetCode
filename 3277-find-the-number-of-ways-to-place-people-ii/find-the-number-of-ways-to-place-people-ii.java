class Solution {
    public int numberOfPairs(int[][] points) {
        Arrays.sort(points,(a,b)->{
            if(a[0]!=b[0]) return Integer.compare(a[0],b[0]);
            else  return Integer.compare(b[1],a[1]);
        });
        int count=0;
        for(int i=0;i<points.length;i++){
            int curX=points[i][0];
            int curY=points[i][1];
            int height=Integer.MAX_VALUE;
            for(int j=i-1;j>=0;j--){
                int prevX=points[j][0];
                int prevY=points[j][1];
                if(prevY < curY) continue;
                if(prevY<height){
                    count++;
                    height=prevY;
                }

            }
        }
        return count;
    }
}