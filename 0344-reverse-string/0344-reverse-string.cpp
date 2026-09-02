class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> ans;

        for(char x:s){
            ans.push(x);
        }
        int i=0;
        while(!ans.empty()){
            s[i]=ans.top();
            ans.pop();
            i++;
        }
    }
};