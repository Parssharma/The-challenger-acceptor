class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(vector<int>& candidates, int target, int index) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Pruning
            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            // Move to next index because each element can be used only once
            solve(candidates, target - candidates[i], i + 1);

            temp.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        solve(candidates, target, 0);

        return ans;
    }
};