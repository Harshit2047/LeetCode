class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(200,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0;i<freq.size();i++){
            if(freq[i]!=0){
                pq.push({freq[i],char(i)});
            }
        }
        string ans="";
        while(pq.size()){
            auto i=pq.top();
            pq.pop();
            int times=i.first;
            char c=i.second;
            while(times--){
                ans+=c;
            }
        }
        return ans;
    }
};