class Solution {
private:
    void solution(int n, vector<string>& ans, int open, int close,
                  string current) {
        
        if(current.size()==2*n){
            ans.push_back(current);
            return ;
        }
        if (open < n) {
            solution(n, ans , open+1, close , current+'(');
        }
        if (open > close) {
            solution(n, ans , open, close+1 , current+')');
        }

    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solution(n, ans,0,0,"");
        return ans;
    }
};