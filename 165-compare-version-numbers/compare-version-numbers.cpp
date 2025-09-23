class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        while(i<version1.length() && j<version2.length()){
            string temp1="";
            string temp2="";
            while(i<version1.length() && version1[i]!='.'){
                temp1+=version1[i];
                i++;
            }
            i++;
             while(j<version2.length() && version2[j]!='.'){
                temp2+=version2[j];
                j++;
            }
            j++;
            int num1=stoi(temp1);
            int num2=stoi(temp2);
            cout<<num1<<num2<<endl;
            if(num1<num2) return -1;
            else if(num1>num2) return 1;
        }

        while(i<version1.length()){
            string temp="";
             while(i<version1.length() && version1[i]!='.'){
                temp+=version1[i];
                i++;
            }
            if(stoi(temp)!=0) return 1;
            i++;
        }

         while(j<version2.length()){
            string temp="";
             while(j<version2.length() && version2[j]!='.'){
                temp+=version2[j];
                j++;
            }
            if(stoi(temp)!=0) return -1;
            j++;
        }
        return 0;
    }
};