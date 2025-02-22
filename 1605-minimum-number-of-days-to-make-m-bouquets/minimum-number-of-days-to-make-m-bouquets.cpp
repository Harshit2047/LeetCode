class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         int kam=INT_MAX;
        int jada=INT_MIN;
        int ans=-1;
        for(auto i:bloomDay){
            kam=min(kam,i);
            jada=max(jada,i);
        }
        int i=kam;
        int j=jada;
        while(i<=j){
            int mid=i+(j-i)/2;
            int count=0;
            int times=k;
            for(int i=0;i<bloomDay.size();i++){
                if(mid>=bloomDay[i]) times--;
                else times=k;
                if(times==0){
                    count++;
                    times=k;
                } 
            }
            if(count>=m){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};