class Solution {
public:
    bool judgeCircle(string moves) {
        int countV=0;
        int countH=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='U') countV++;
            else if(moves[i]=='D') countV--;
            else if(moves[i]=='R') countH++;
            else countH--;
        }
        return (countV==0 && countH==0);
    }
};