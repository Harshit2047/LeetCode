class Solution {
public:
    int minSwaps(string s) {
        int count =0;
        for(auto it: s)
        {
            if(it=='[')
            {
                count++;
            }
            else if(count>0)
            {
                count--;
            }
        }
        return (count+1)/2;
        
    }
};