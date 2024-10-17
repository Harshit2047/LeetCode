// class Solution {
// public:
//     int maximumSwap(int num) {
//         string st = to_string(num);
//         int n = st.size();
//         priority_queue<pair<char, int>> pq;
//         for(int i = 0; i < n; i++)
//         {
//             pq.push({st[i], i});
//         }
//         for(int j = 0; j < n; j++)
//         {
//             while(! pq.empty() && pq.top().second < j) pq.pop();
//                 if(pq.top().first > st[j])
//                 {
//                     swap(st[j], st[pq.top().second]);
//                     break;
//                 }            
//         }
//         return stoi(st);
//     }
// };



class Solution {
public: 
    
 
    int maximumSwap(int num) {
        string s=to_string(num);
     priority_queue<pair<int,int>> pq;
        for(int i=0;i<s.size();i++){
            pq.push({s[i]-'0',i});
        }
        for(int i=0;i<s.size();i++){
            while(!pq.empty() && pq.top().second < i)pq.pop();
            auto x = pq.top();
            
            if(s[i]-'0'<x.first){
                swap(s[i],s[x.second]);
                break;
            }
        }
        return stoi(s);
    }
};