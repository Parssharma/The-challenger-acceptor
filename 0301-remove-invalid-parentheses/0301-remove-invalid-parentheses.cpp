class Solution {
public:
    vector<string> ans;

    void solve(string s, int start, int last,
               char open, char close) {

        int balance = 0;

        for (int i = start; i < s.size(); i++) {

            if (s[i] == open)
                balance++;

            if (s[i] == close)
                balance--;

            // Extra closing bracket
            if (balance < 0) {

                for (int j = last; j <= i; j++) {

                    if (s[j] != close)
                        continue;

                    // Skip duplicate removals
                    if (j > last && s[j] == s[j - 1])
                        continue;

                    string next = s.substr(0, j)
                                + s.substr(j + 1);

                    solve(next, i, j, open, close);
                }

                return;
            }
        }

        // First check: extra ')'
        // Now check for extra '('
        if (open == '(') {

            reverse(s.begin(), s.end());

            solve(s, 0, 0, ')', '(');

        } else {

            // s is reversed here, so reverse it back
            reverse(s.begin(), s.end());

            ans.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        solve(s, 0, 0, '(', ')');

        return ans;
    }
};