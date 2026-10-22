class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root==nullptr){
        return NULL;
       }

       if(root==p || root==q){
        return root;
       }

       TreeNode* leftans= lowestCommonAncestor(root->left,p,q);
       TreeNode* rightans= lowestCommonAncestor(root->right,p,q);

       if(leftans!=nullptr && rightans !=nullptr){
        return root;
       }

       if(leftans !=nullptr && rightans ==nullptr){
        return leftans;
       }

       if(leftans ==nullptr && rightans !=nullptr){
        return rightans;
       }

       if(leftans==nullptr && rightans==nullptr){
        return NULL;
       }
        return root;
    }     
};