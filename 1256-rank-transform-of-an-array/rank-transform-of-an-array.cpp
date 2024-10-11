class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v(arr);
        sort(v.begin(),v.end());
        map<int,int> mp;
        int idx=1;
        for(int i=0;i<v.size();i++){
            if(mp.find(v[i])==mp.end()){
                mp[v[i]]=idx;
                idx++;
            }
        }
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                arr[i]=mp[arr[i]];
            }
        }
        return arr;
    }
};