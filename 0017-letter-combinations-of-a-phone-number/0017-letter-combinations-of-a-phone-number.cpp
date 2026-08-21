class Solution {
public:
    vector<string> ans;

    void solve(int index, string digits,
               vector<string>& mp, string current) {

        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }
        int number =digits[index] - '0';
        string letters = mp[number];

        for(char ch : letters) {
            solve(index + 1,
                  digits,
                  mp,
                  current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        solve(0, digits, mp, "");

        return ans;
    }
};