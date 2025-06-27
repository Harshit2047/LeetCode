class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        int Count=0;
        queue<pair<string,int>> q;
        q.push({beginWord,Count});
        while(q.size()){
            string temp=q.front().first;
            int CountTemp=q.front().second+1;
            if(temp==endWord) return CountTemp;
            q.pop();
            for(int i=0;i<temp.size();i++){
                string s=temp;
                for(char j='a';j<='z';j++){
                    temp[i]=j;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,CountTemp});
                    }
                }
                temp=s;
            }
        }
        return 0;
    }
};