class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> vowel(26,0);
        vector<int> con(26,0);
        int freq1=0;
        int freq2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u'){
                vowel[s[i]-'a']++;
                int num=vowel[s[i]-'a'];
                if(freq1<num){
                    freq1=num;
                }
            }
            else {
                con[s[i]-'a']++;
                int num=con[s[i]-'a'];
                if(freq2<num){
                    freq2=num;
                }
            }
        }
        return freq1+freq2;
    }
};