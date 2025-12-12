class Solution {
public:
    struct cmp{
         bool operator()(const vector<string> &v1, const vector<string> &v2) const {
            int t1 = stoi(v1[1]);
            int t2 = stoi(v2[1]);
            if (t1 != t2) return t1 < t2;
            // Same timestamp: OFFLINE should come before MESSAGE
            if (v1[0] == v2[0]) return false;         // same type -> stable
            if (v1[0] == "OFFLINE") return true;      // OFFLINE before MESSAGE
            return false;                             // MESSAGE after OFFLINE
        }
    };
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> ans(numberOfUsers,0);
        sort(events.begin(),events.end(),cmp());
        unordered_map<int,int> mp;
        for(int i=0;i<numberOfUsers;i++){
            mp[i]=0;
        }
        for(auto v:events){
            if(v[0]=="MESSAGE"){
                string ids=v[2];
                stringstream ss(ids);
                string temp="";
                int time=stoi(v[1]);
                while(ss>>temp){
                    if(temp=="ALL"){
                        for(int i=0;i<ans.size();i++){
                            ans[i]++;
                        }
                    }
                    else if(temp=="HERE"){
                        for(auto i:mp){
                            if(i.second<=time){
                                ans[i.first]++;
                            }
                        }
                    }
                    else {
                          int id=stoi(temp.substr(2));
                          ans[id]++;
                    }
                    
                }

            }
            else{
                mp[stoi(v[2])]=(stoi(v[1]))+60;
            }
        }
        return ans;

    }
};