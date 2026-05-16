public class Solution {
    public string LongestPalindrome(string s) {
        int n=s.Length;
        int[][] arr=new int[n][];
        int maxLength=int.MinValue;
        int start=-1;
        int end=-1;
        for(int i=0;i<arr.Length;i++){
            arr[i]=new int[n];
        }

        for(int k=0;k<n;k++){
            int i=0;
            int j=k;
            while(j<n && i<n){
                if(i==j){
                        arr[i][j]=1;
                        if(maxLength<j-i+1){
                            maxLength=j-i+1;
                            start=i;
                            end=j;
                        }
                }
                else if(j-i==1){
                   if(s[i]==s[j]){
                        arr[i][j]=1;
                        if(maxLength<j-i+1){
                            maxLength=j-i+1;
                            start=i;
                            end=j;
                        }
                   }
                }
                else{
                    if(s[i]==s[j] && arr[i+1][j-1]==1){
                        arr[i][j]=1;
                        if(maxLength<j-i+1){
                            maxLength=j-i+1;
                            start=i;
                            end=j;
                        }
                    }
                }
                j++;i++;
            }
        }
    return s.Substring(start,end-start+1);
    }
}