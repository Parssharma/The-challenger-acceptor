class Solution {
public:
    string predictPartyVictory(string senate) {
        deque<int> R;
        deque<int> D;

        int n = senate.size();

        // Store indices
        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                R.push_back(i);
            } else {
                D.push_back(i);
            }
        }

        while (!R.empty() && !D.empty()) {

            int r = R.front();
            int d = D.front();

            R.pop_front();
            D.pop_front();

            if (r < d) {
                // R gets the turn and bans D
                R.push_back(r + n);
            } else {
                // D gets the turn and bans R
                D.push_back(d + n);
            }
        }

        if (R.empty()) {
            return "Dire";
        }

        return "Radiant";
    }
};