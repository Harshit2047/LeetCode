class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count=0;
        for(int i=0;i<words.size();i++){
            string a=words[i];
            bool temp=false;
            for(int j=0;j<pref.size();j++){
                if(pref[j]==a[j]){
                    temp=true;
                }
                else{
                    temp=false;
                    break;
                }
            }
            if(temp)count++;
        }
        return count;
    }
};