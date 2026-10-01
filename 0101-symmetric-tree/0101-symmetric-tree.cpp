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
    bool check(TreeNode* root , TreeNode* root2){
            if(root==nullptr && root2==nullptr){
                return true;
            }
            if(root==nullptr && root2 !=nullptr){
                return false;
            }
            if(root!=nullptr && root2==nullptr){
                return false;
            }
            if(root->val!=root2->val){
                return false;
            }
          return(
           check(root->left,root2->right) &&

            check(root2->left,root->right)
          ) ;
            
            
            
    }
public:
  bool isSymmetric(TreeNode* root) {
    if(root == nullptr){
        return true;
    }

    return check(root->left, root->right);
}
};