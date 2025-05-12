class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<digits.size();i++){
            m[digits[i]]++;
        }
        for(int i=100;i<=999;i=i+2){
            int num=i;
            int a=num%10;
            num=num/10;
            int b=num%10;
            num=num/10;
            int c=num;
            if(m.find(a)!=m.end()){
                m[a]--;
                if(m[a]==0) m.erase(a);
                if(m.find(b)!=m.end()){
                    m[b]--;
                    if(m[b]==0) m.erase(b);
                    if(m.find(c)!=m.end()){
                        ans.push_back(i);
                    }
                    m[b]++;
                }
                m[a]++;
            }
        }
        return ans;
    }
};