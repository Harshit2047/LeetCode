class Solution {
public:
    string compressedString(string word) {
        string s="";
        int i=0;
        int j=0;
        int count=0;
       while(i<word.length()){
        count=0;
        while(j<word.length() && word[i]==word[j] && count<9){
            count++;
            j++;
        }
        s+=to_string(count)+word[i];
        i=j;
       }
       return s;
    }
};