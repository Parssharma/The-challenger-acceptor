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
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
             int maxVal = INT_MIN;

            for(int i=0;i<=size-1;i++){
                TreeNode* val=q.front();
                q.pop();

                maxVal = max(maxVal, val->val);

                if(val->left){
                    q.push(val->left);
                }
                if(val->right){
                    q.push(val->right);
                }

            }
                ans.push_back(maxVal);
        }
        return ans;
    }
};