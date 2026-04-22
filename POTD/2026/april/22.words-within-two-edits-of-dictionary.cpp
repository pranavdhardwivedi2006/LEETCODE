class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto& q : queries) {
            for(auto& dict : dictionary) {
                int n = q.size(), cnt = 0;
                for(int i = 0; i < n; i++) {
                    if(q[i] != dict[i]) cnt++;
                }
                if(cnt <= 2) {
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};