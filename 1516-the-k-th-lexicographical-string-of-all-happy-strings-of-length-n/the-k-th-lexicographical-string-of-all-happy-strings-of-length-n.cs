public class Solution {
    void helper(int n,List<char> arr,List<string> ans,int idx,StringBuilder s){
        if(n==0){
            ans.Add(s.ToString());
            return;
        }
        for(int i=0;i<arr.Count;i++){
            if(idx!=i){
                s.Append(arr[i]);
                helper(n-1,arr,ans,i,s);
                s.Length--;
            }
        }
    }
    public string GetHappyString(int n, int k) {
        List<char> arr=new List<char>{'a','b','c'};
        StringBuilder s=new StringBuilder();
        List<string> ans=new List<string>();
        helper(n,arr,ans,-1,s);
        if(ans.Count < k) return "";
        return ans[k-1];
    }
}