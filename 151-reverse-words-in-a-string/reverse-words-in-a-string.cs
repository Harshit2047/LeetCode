public class Solution {
    public string ReverseWords(string s) {
        string[] arr=s.Split(' ');
        StringBuilder sb=new StringBuilder();
        for(int i=arr.Length-1;i>=0;i--){
            if(arr[i].Trim()!=""){
                if(sb.Length > 0) sb.Append(" ");
                sb.Append(arr[i]);
            }
        }
        return sb.ToString();
    }
}