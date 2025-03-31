class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int ans = 0;
        
        while (i <= j) {
            leftMax = max(height[i], leftMax);
            rightMax = max(height[j], rightMax);  // Fix: Use height[j]
            
            if (leftMax <= rightMax) {
                ans += leftMax - height[i];
                i++;
            } else {
                ans += rightMax - height[j];  // Fix: Use height[j]
                j--;
            }
        }
        
        return ans;
    }
};
