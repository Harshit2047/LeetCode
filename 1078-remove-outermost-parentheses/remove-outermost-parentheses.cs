public class Solution {
    public string RemoveOuterParentheses(string l) {
        StringBuilder sb=new StringBuilder(l);
        int idx=sb.Length-1;
        int count=0;
        for(int i=sb.Length-1;i>=0;i--){
            if(sb[i]==')') count++;
            else{
                count--;
            }
            if(count==0){
                sb.Remove(idx,1);
                sb.Remove(i, 1);
                idx=i-1;
                count=0;
            }
        }
        return sb.ToString();

    }
}