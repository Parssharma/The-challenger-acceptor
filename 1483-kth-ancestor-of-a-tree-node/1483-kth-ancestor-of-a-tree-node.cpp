class TreeAncestor {
public:
    vector<vector<int>> up;
    int LOG = 17;

    TreeAncestor(int n, vector<int>& parent) {

        up.assign(n, vector<int>(LOG, -1));

        // Store direct parents
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Build binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {

                int mid = up[i][j - 1];

                if (mid != -1) {
                    up[i][j] = up[mid][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {

        for (int j = 0; j < LOG; j++) {

            if (k & (1 << j)) {
                node = up[node][j];

                if (node == -1) {
                    return -1;
                }
            }
        }

        return node;
    }
};