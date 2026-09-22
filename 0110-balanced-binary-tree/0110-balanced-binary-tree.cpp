class Solution {
public:
    pair<bool,int> isBalancedfast(TreeNode* root) {
        if(root == nullptr) {
            return make_pair(true, 0);
        }

        pair<bool,int> left = isBalancedfast(root->left);
        pair<bool,int> right = isBalancedfast(root->right);

        bool leftans = left.first;
        bool rightans = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;

        ans.second = max(left.second, right.second) + 1;

        if(leftans && rightans && diff) {
            ans.first = true;
        }
        else {
            ans.first = false;
        }

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        return isBalancedfast(root).first;
    }
};