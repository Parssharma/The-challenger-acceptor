class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;

        if(root == nullptr){
            return result;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool LefttoRight = true;

        while(!q.empty()){

            int size = q.size();

            vector<int> ans(size);

            for(int i = 0; i < size; i++){

                TreeNode* frontnode = q.front();
                q.pop();

                int index = LefttoRight ? i : size - i - 1;

                ans[index] = frontnode->val;

                if(frontnode->left){
                    q.push(frontnode->left);
                }

                if(frontnode->right){
                    q.push(frontnode->right);
                }
            }

            LefttoRight = !LefttoRight;

            result.push_back(ans);
        }

        return result;
    }
};