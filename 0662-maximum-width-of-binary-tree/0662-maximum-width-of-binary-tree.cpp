class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        unsigned long long ans = 0;

        while (!q.empty()) {
            int size = q.size();

            unsigned long long start = 0;
            unsigned long long end = 0;

            unsigned long long base = q.front().second;

            for (int i = 0; i < size; i++) {

                auto front = q.front();
                q.pop();

                TreeNode* node = front.first;
                unsigned long long index = front.second - base;

                if (i == 0) start = index;
                if (i == size - 1) end = index;

                if (node->left) {
                    q.push({node->left, 2 * index + 1});
                }

                if (node->right) {
                    q.push({node->right, 2 * index + 2});
                }
            }

            ans = max(ans, end - start + 1);
        }

        return static_cast<int>(ans);
    }
};
 