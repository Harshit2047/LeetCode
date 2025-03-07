class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int first = -1, second = -1, minDist = INT_MAX;
        vector<int> ans = {-1, -1};

        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (first == -1) {
                    first = i;
                } else {
                    second = i;
                    if (second - first < minDist) {
                        minDist = second - first;
                        ans = {first, second};
                    }
                    first = second;
                }
            }
        }
        return ans;
    }
};
