
class Solution {
public:
    int minInsertions(string s) {
        int brace = 0;
        int req = 0;

        for (char i : s) {
            if (i == '(') {
                brace += 2;

                if (brace % 2 != 0) {
                    req++;
                    brace--;
                }
            } 
            else {
                brace--;

                if (brace < 0) {
                    req++;
                    brace = 1;
                }
            }
        }

        return brace + req;
    }
};