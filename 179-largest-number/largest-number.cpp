class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp=[](int num1,int num2){
            string s1=to_string(num1);
            string s2=to_string(num2);
            if(s1+s2>s2+s1)return true;
            else return false;
        };
        sort(nums.begin(),nums.end(),comp);
        string ans="";
        if(nums[0]==0) return "0";
        for(int i=0;i<nums.size();i++){
            ans+=to_string(nums[i]);
        }
        return ans;
    }
};