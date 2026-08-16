class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxDeque;
        deque<int> minDeque;

        int left = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Maintain decreasing deque for maximum
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[i]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(i);

            // Maintain increasing deque for minimum
            while (!minDeque.empty() && nums[minDeque.back()] > nums[i]) {
                minDeque.pop_back();
            }
            minDeque.push_back(i);

            // Shrink window if max - min exceeds limit
            while (nums[maxDeque.front()] - nums[minDeque.front()] > limit) {

                if (maxDeque.front() == left) {
                    maxDeque.pop_front();
                }

                if (minDeque.front() == left) {
                    minDeque.pop_front();
                }

                left++;
            }

            // Length of current valid subarray
            ans = max(ans, i - left + 1);
        }

        return ans;
    }
};