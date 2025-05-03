class Solution {
public:
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int topRotations = 0, bottomRotations = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target)
                return INT_MAX; 
            else if (tops[i] != target)
                topRotations++;
            else if (bottoms[i] != target)
                bottomRotations++;
        }
        return min(topRotations, bottomRotations);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int rotations = min(check(tops[0], tops, bottoms), check(bottoms[0], tops, bottoms));
        return rotations == INT_MAX ? -1 : rotations;
    }
};
