class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int MaxC=0;
        for(auto i:s){
            if(s.find(i-1)==s.end()){
                int x=i;
                int count=1;
                while(s.find(x+1)!=s.end()){
                    count++;
                    x++;
                } 
                MaxC=max(MaxC,count);
            }
        }
        return MaxC;
    }
};