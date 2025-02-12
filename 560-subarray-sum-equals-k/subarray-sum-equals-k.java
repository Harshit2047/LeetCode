class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer>map=new HashMap<>();
        int sum=0,c=0,zc=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(map.containsKey(sum-k)) c+=map.get(sum-k);
            if(sum==k) c++;
            if(map.containsKey(sum)) map.put(sum,map.get(sum)+1);
            else map.put(sum,1);
        }
        if(zc>=2) zc=zc-1;
        return c+zc;
    }
}