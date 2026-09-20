class Solution {
    vector<int> ans;

    void solve(TreeNode* root) {
        if(root == nullptr)
            return;

        ans.push_back(root->val);

        solve(root->left);
        solve(root->right);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        solve(root);
        return ans;
    }
};