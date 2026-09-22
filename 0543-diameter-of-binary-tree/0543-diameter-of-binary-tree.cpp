/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int height(TreeNode* root){
       if(root==nullptr){
        return 0;
       } 

       int left=height(root->left);
       int right=height(root->right);

       int ans = max(left,right)+1;
       return ans;
    }


    pair<int, int> fastcal(TreeNode* root) {

        // {diameter, height}
        if (root == nullptr) {
            return {0, 0};
        }

        pair<int, int> left = fastcal(root->left);
        pair<int, int> right = fastcal(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        int diameter = max(op1, max(op2, op3));

        int height = max(left.second, right.second) + 1;

        return {diameter, height};
    }

public:

    int diameterOfBinaryTree(TreeNode* root) {
        return fastcal(root).first;
    }
};
