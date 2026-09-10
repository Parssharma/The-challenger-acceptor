class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        build(numRows, ans);
        return ans;
    }

    void build(int n, vector<vector<int>>& ans) {
        if (n == 0)
            return;

        // First build previous rows
        build(n - 1, ans);

        // Create current row
        vector<int> row(n, 1);

        for (int j = 1; j < n - 1; j++) {
            row[j] = ans[n - 2][j - 1] + ans[n - 2][j];
        }

        ans.push_back(row);
    }
};