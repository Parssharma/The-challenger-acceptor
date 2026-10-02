/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }

        map<int, int> sidenode;
        queue<pair<TreeNode*, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            TreeNode* frontnode = temp.first;
            int vd = temp.second;
            // if 1 value is present for a vd , then dont accept other
            sidenode[vd] = frontnode->val;

            if (frontnode->left) {
                q.push(make_pair(frontnode->left, vd + 1));
            }
            if (frontnode->right) {
                q.push(make_pair(frontnode->right, vd + 1));
            }
        }
        for (auto i : sidenode) {
            ans.push_back(i.second);
        }
        return ans;
    }
};