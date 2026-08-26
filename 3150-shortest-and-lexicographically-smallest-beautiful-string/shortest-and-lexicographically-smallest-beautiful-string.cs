public class Solution {
    public bool helper(string s1, string s2){
        int i = 0;
        int j = 0;

        while(i < s1.Length && j < s2.Length){
            if(s1[i] < s2[j]) return true;
            else if(s1[i] > s2[j]) return false;

            i++;
            j++;
        }

        if(i < s1.Length) return false;
        else if(j < s2.Length) return true;

        return false;
    }

    public string ShortestBeautifulSubstring(string s, int k) {
        int i = 0;

        Dictionary<char,int> dir = new Dictionary<char,int>();

        int minLength = int.MaxValue;
        int start = -1;
        int end = -1;

        for(int j = 0; j < s.Length; j++){

            if(dir.ContainsKey(s[j])){
                dir[s[j]]++;
            }
            else{
                dir[s[j]] = 1;
            }

            while(dir.ContainsKey('1') && dir['1'] == k){

                int currentLength = j - i + 1;

                if(currentLength < minLength){
                    minLength = currentLength;
                    start = i;
                    end = j;
                }
                else if(currentLength == minLength){

                    string current = s.Substring(i, currentLength);
                    string previous = s.Substring(start, minLength);

                    if(helper(current, previous)){
                        start = i;
                        end = j;
                    }
                }

                dir[s[i]]--;

                if(dir[s[i]] == 0){
                    dir.Remove(s[i]);
                }

                i++;
            }
        }

        if(start == -1 || end == -1) return "";

        return s.Substring(start, end - start + 1);
    }
}