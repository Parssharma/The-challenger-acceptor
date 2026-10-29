class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr && subRoot == nullptr)
            return true;

        if (root == nullptr || subRoot == nullptr)
            return false;

        if (root->val != subRoot->val)
            return false;

        return isSame(root->left, subRoot->left) &&
               isSame(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr)
            return true;

        if (root == nullptr)
            return false;

        if (isSame(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};