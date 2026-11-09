
class Solution {
public:
    int count = 0;
    int ans = 0;

    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr || count >= k) {
            return ans;
        }

        kthSmallest(root->left, k);

        if (count >= k) {
            return ans;
        }

        count++;

        if (count == k) {
            ans = root->val;
            return ans;
        }

        kthSmallest(root->right, k);

        return ans;
    }
};
