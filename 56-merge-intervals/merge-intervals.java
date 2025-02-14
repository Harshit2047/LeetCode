class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));
        List<List<Integer>>list=new ArrayList<>();
        int m=intervals.length;
        for(int i=0;i<m;i++){
            int a=intervals[i][0];
            int b=intervals[i][1];
            while(i<=m-2 && intervals[i+1][0]<=b){
                b = Math.max(b, intervals[i + 1][1]);
                i++;
            }
            List<Integer>arr=new ArrayList<>();
            arr.add(a);
            arr.add(b);
            list.add(new ArrayList(arr));
            
            
        }
        System.out.println(list);
        int ans[][]=new int[list.size()][2];
        for(int i=0;i<list.size();i++){
            ans[i][0]=list.get(i).get(0);
            ans[i][1]=list.get(i).get(1);
        }
        return ans;
    } 
}