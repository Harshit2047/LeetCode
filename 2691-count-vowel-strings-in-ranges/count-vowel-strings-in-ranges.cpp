class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size());
        int sum=0;
        for(int i=0;i<words.size();i++){
            string w=words[i];
            if(isVowel(w[0]) && isVowel(w[w.size()-1])){
                sum=sum+1;
            }
            prefix[i]=sum;
        }
        vector<int> ans;
        for (auto& q : queries) {
            int start = q[0];
            int end = q[1];
            if (start == 0) {
                ans.push_back(prefix[end]);
            } else {
                ans.push_back(prefix[end] - prefix[start - 1]);
            }
        }
        return ans;
    }
};