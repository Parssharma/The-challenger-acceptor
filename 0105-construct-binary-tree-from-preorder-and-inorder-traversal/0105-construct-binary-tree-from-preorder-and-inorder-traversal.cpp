
class Solution {
public:
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    vector<int>& inorder,
                    int start, int end) {

        // Base case
        if (start > end) {
            return nullptr;
        }

        // Step 1: Create root from preorder
        int rootVal = preorder[preIndex];
        preIndex++;

        TreeNode* root = new TreeNode(rootVal);

        // Step 2: Find root index in inorder
        int index = -1;

        for (int i = start; i <= end; i++) {
            if (inorder[i] == rootVal) {
                index = i;
                break;
            }
        }

        // Step 3: Construct left subtree
        root->left = build(preorder, inorder,
                           start, index - 1);

        // Step 4: Construct right subtree
        root->right = build(preorder, inorder,
                            index + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        preIndex = 0;

        return build(preorder, inorder,
                     0, inorder.size() - 1);
    }
};
