class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length() != goal.length())return false;
        string added = s+s;
        if(added.find(goal) == -1)
        {
            return false;
        }
        return true;
        
    }
};