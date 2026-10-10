class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int mx = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            mx = max(mx, diff[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int low = 0, high = mx;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(0, d - mid);
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long ops = 0;
        long long ans = 0;

        for (int d : diff) {
            ops += max(0, d - level);
            int finalDiff = min(d, level);
            ans += 1LL * finalDiff * finalDiff;
        }

        long long remaining = k - ops;
        ans -= remaining * (2LL * level - 1);

        return ans;
    }
};