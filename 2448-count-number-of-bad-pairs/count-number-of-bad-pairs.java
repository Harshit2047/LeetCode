class Solution {
    long sum(long n){
        return (long)n*(long)(2+(n-1))/2;
    }
    public long countBadPairs(int[] nums) {
        int n=nums.length;
        HashMap<Long,Long>map=new HashMap<>();
        long pairs=(sum(n-1));
        for(int i=0;i<n;i++){
            long diff=(long)nums[i]-i;
            if(map.containsKey(diff)){
                map.put(diff,map.get(diff)+1);
            }
            else{
                map.put(diff,(long)1);
            }
        }
        long sum1=0;
        for(long ele:map.values()){
            if(ele>1){
                sum1+=sum(ele-1);
            }
        }
        return pairs-sum1;
    }
}