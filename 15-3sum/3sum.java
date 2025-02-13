class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        HashMap<Integer,Integer>map=new HashMap<>();
        List<List<Integer>>ans=new ArrayList<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            map.put(nums[i],i);
        }
        HashSet<List<Integer>> set = new HashSet<>();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int sum=-1*(nums[i]+nums[j]);
                if(map.containsKey(sum) && i!=map.get(sum) && j!=map.get(sum)){
                    List<Integer>a=new ArrayList<>();
                    a.add(nums[i]);
                    a.add(nums[j]);
                    a.add(sum);
                    Collections.sort(a);
                    if(!set.contains(a)) {
                        ans.add(new ArrayList<>(a));
                        set.add(a);
                    }
                }
                // map.put(nums[i],i);
            }
        }
        return ans;
    }
}