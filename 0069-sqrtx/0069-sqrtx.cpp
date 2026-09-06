class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        long long low = 1;
        long long high = x / 2;
        int ans = 1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (mid <= x / mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};