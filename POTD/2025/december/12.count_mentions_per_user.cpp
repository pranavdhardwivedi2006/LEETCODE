class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int curr = 0, n = numberOfUsers;
        vector<int> ans(n), off(n); 
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            if(stoi(a[1]) == stoi(b[1])) return a[0] > b[0];
            return stoi(a[1]) < stoi(b[1]);
        });
        for(auto& it : events) {
            int time = stoi(it[1]);
            if(it[0] == "MESSAGE") {
                if(it[2] == "ALL") for(auto& x : ans) x++;
                else if(it[2] == "HERE") {
                    for(int i = 0; i < n; i++) {
                        if(off[i] <= time) ans[i]++;
                    }
                }
                else {
                    int i = 2, s = it[2].size(), id = 0;
                    while(i < s) {
                        while(i < s && it[2][i] != ' ') id = id * 10 + (it[2][i++] - '0');
                        ans[id]++; i += 3; id = 0;
                    }
                }
            }
            else off[stoi(it[2])] = time + 60;
            curr++;
        }
        return ans;
    }
};