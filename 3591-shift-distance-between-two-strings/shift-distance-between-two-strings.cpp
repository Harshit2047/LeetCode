class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long sum = 0;
        for (int i = 0; i < s.length(); i++) {
            int Nx = s[i] - 'a';
            int Px = s[i] - 'a';
            int y = t[i] - 'a';
            long long nCost = 0;
            long long pCost = 0;          
            while (Nx != y) {
                nCost += nextCost[Nx];
                 Nx = (Nx+1) % 26;
                
            }           
            while (Px != y) {
                pCost += previousCost[Px]; 
                Px = (Px - 1 + 26) % 26; 
            }

            sum += min(nCost, pCost);
        }
        return sum;
    }
};
