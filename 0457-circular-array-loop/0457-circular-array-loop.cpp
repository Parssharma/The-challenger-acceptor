class Solution {
public:

    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

    bool circularArrayLoop(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool direction = nums[i] > 0;

            int slow = i;
            int fast = nextIndex(nums, i);

            while (
                (nums[slow] > 0) == direction &&
                (nums[fast] > 0) == direction &&
                (nums[nextIndex(nums, fast)] > 0) == direction
            ) {

                if (slow == fast) {

                    // Don't accept a one-element cycle
                    if (slow != nextIndex(nums, slow))
                        return true;

                    break;
                }

                slow = nextIndex(nums, slow);

                fast = nextIndex(nums, fast);
                fast = nextIndex(nums, fast);
            }
        }

        return false;
    }
};