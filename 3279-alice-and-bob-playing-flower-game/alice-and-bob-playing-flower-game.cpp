class Solution { 
public:     
    long long flowerGame(int n, int m) {         
        long long count=0;         
        long long Firsteven=0;         
         long long  Secondeven=0;         
         long long  Firstodd=0;         
         long long  Secondodd=0;         

        if(n%2!=0){             
            Firstodd=(n/2)+1;             
            Firsteven=(n-Firstodd);         
        }         
        else{             
            Firsteven=n/2;             
            Firstodd=n/2;         
        }           

        if(m%2!=0){             
            Secondodd=(m/2)+1;             
            Secondeven=(m-Secondodd);         
        }         
        else{             
            Secondeven=m/2;             
            Secondodd=m/2;         
        }                  

        count=(Firsteven*Secondodd)+(Secondeven*Firstodd);   

        return count;     
    } 
};
