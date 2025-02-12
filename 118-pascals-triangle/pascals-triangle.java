class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>>ans=new ArrayList<>();
        ans.add(new ArrayList<>());
        // ans.add(new ArrayList<>());
        ans.get(0).add(1);
        if(n==1) return ans;
        ans.add(new ArrayList<>());
        ans.get(1).add(1);ans.get(1).add(1);
        if(n==2) return ans;
        for(int i=2;i<n;i++){
            ans.add(new ArrayList<>());
            for(int j=0;j<=ans.get(i-1).size();j++){
                if(j==0||j==ans.get(i-1).size()){
                    ans.get(i).add(1);
                }
                else{
                    ans.get(i).add(ans.get(i-1).get(j)+ans.get(i-1).get(j-1));
                }
            }
        }
        return ans;
    }
}