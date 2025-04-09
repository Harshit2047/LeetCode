class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int, int> mp;
        for(int card : hand) mp[card]++;

        while(!mp.empty()) {
            int start = mp.begin()->first;

            for(int i = 0; i < groupSize; i++) {
                if(mp[start + i] == 0) return false;
                mp[start + i]--;
                if(mp[start + i] == 0) mp.erase(start + i);
            }
        }

        return true;
    }
};
