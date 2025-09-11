class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>> q;
        for(auto i:s){
            if(i=='A' || i=='E' ||i=='I'|| i=='O' || i=='U' || i=='a' || i=='e' ||i=='i'|| i=='o' || i=='u'){
                q.push(i);
            }
        }
       
        for(int j=0;j<s.length();j++){
            char i=s[j];
            if(i=='A' || i=='E' ||i=='I'|| i=='O' || i=='U' || i=='a' || i=='e' ||i=='i'|| i=='o' || i=='u'){
                s[j]=q.top();
                q.pop();
            }
        }
        return s;
    }
};