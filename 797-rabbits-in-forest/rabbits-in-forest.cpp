class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int> mp;
        int count=0;

        for(int i=0;i<answers.size();i++){
            if(answers[i]==0){
                count=count+1;
                continue;
            }
            if(mp.find(answers[i]+1)==mp.end()){
                mp[answers[i]+1]=1;
                count=count+answers[i]+1;
            }
            else{
                mp[answers[i]+1]++;
                int key=answers[i]+1;
                int val=mp[answers[i]+1];
                if(key==val){
                    mp.erase(answers[i]+1);
                }
            }
        }
        return count;
    }
};