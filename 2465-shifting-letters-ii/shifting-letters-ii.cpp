class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> arr(s.size()+1,0);
        for(auto i:shifts){
            if(i[2]==1){
                arr[i[0]]++;
                arr[i[1]+1]--;
            }
            else{
                arr[i[1]+1]++;
                arr[i[0]]--;
            }
        }

        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]+arr[i-1];
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
    if (arr[i] >= 0) {
        arr[i] = arr[i] % 26; // Keep shifts within bounds
        int val = (s[i] - 'a' + arr[i]) % 26; // Calculate new position
        ans += (char)('a' + val); // Convert back to character
    } else {
        arr[i] = (arr[i] % 26 + 26) % 26; // Handle negative shifts properly
        int val = (s[i] - 'a' + arr[i]) % 26; // Calculate new position
        ans += (char)('a' + val); // Convert back to character
    }
}

        return ans;
    }
};