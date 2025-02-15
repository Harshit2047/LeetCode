class Solution {
public:
    bool helper(string s,int comp,int sum){
        if(s.length()==0){
            if(sum==comp) return true;
            else return false;
        }
        for(int i=1;i<=s.length();i++){
            string take=s.substr(0,i);
            string left=s.substr(i);
            if(helper(left,comp,sum+stoi(take))) return true;
        }
        return false;
        
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            int val=i*i;
            if(helper(to_string(val),i,0)){
                ans+=val;
            }
        }
        return ans;
    }
};