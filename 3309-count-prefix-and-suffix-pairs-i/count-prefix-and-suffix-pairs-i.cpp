class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            string a = words[i];
            for (int j = i + 1; j < words.size(); j++) {
                string b = words[j];
                if (a.size() > b.size())  continue;
                bool pre=false;
                for(int p=0;p<a.size();p++){
                    if(a[p]==b[p]){
                        pre=true;
                    }
                    else{
                        pre=false;
                        break;
                    }
                }
                bool suf=false;
                int x=0;
                int y=b.size()-a.size();
                while(x<a.size()){
                     if(a[x]==b[y]){
                        suf=true;
                    }
                    else{
                        suf=false;
                        break;
                    }
                    x++;
                    y++;
                }
                if(pre && suf) count++;
            }
        }
        return count;
    }
};