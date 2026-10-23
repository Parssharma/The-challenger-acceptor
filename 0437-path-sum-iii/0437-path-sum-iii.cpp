class Solution {
public:
    void solve(TreeNode* root, long long targetSum,
               vector<int>& path, int& count) {

        if (root == nullptr) {
            return;
        }

        // Add current node to path
        path.push_back(root->val);

        long long sum = 0;

        // Check all possible downward paths ending at current node
        for (int i = path.size() - 1; i >= 0; i--) {
            sum += path[i];

            if (sum == targetSum) {
                count++;
            }
        }

        // Explore left and right subtrees
        solve(root->left, targetSum, path, count);
        solve(root->right, targetSum, path, count);

        // Backtracking
        path.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int count = 0;

        solve(root, targetSum, path, count);

        return count;
    }
};