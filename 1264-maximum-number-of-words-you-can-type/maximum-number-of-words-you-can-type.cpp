class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> st;
        for(auto i:brokenLetters) st.insert(i);
        stringstream ss(text);
        string temp="";
        int count=1;
        while(ss>>temp){
            bool flag=true;
            for(auto i:temp){
                if(st.find(i)!=st.end()){
                    flag=false;
                    break;
                }
            }
            if(flag==true) count++;
        }
        return count-1;
    }
};