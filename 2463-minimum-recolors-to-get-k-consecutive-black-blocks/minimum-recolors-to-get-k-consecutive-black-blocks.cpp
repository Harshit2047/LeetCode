class Solution {
public:
    int minimumRecolors(string nums, int k) {
        int i = 0, j = 0;
        int countW = 0, minW = INT_MAX;
        
        
        for (j = 0; j < k; j++) {
            if (nums[j] == 'W') countW++;
        }

        minW = countW; 

   
        while (j < nums.size()) {
            if (nums[i] == 'W') countW--; 
            if (nums[j] == 'W') countW++;  
            
            minW = min(minW, countW); 
            
            i++; j++;
        }

        return minW;
    }
};
