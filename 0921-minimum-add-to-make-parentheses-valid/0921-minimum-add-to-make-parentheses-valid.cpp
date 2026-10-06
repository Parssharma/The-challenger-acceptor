class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push(i);
            }
            else if(s[i] == ')') {

                if(!st.empty() && s[st.top()] == '(') {
                    st.pop();
                }
                else {
                    st.push(i);
                }
            }
        }

        int count = 0;

        while(!st.empty()) {
            count++;
            st.pop();
        }

        return count;
    }
};