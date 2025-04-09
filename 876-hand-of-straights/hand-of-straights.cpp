class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:hand){
            pq.push(i);
        }
        vector<int> ans;
        vector<int> temp;
        while(pq.size()){
            if(ans.size()==0 || ans.back()+1==pq.top()){
                ans.push_back(pq.top());
            }
            else temp.push_back(pq.top());
            pq.pop();
            if(ans.size()==groupSize){
                ans.clear();
                for(auto x:temp){
                    pq.push(x);
                }
                temp.clear();
            }
        }
        cout<<ans.size()<<"" ;
        if(ans.size()==0) return true;
        else return false;
    }
};