class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        int i = 0, n = words.size();
        string prev; int cnt = 0, ans = 0;
        while(i < n) {
            if(words[i].size() >= k) {
                string temp;
                for(int j = 0; j < k; j++) {
                    temp += words[i][j];
                }
                if(temp == prev) cnt++;
                else {
                    if(cnt > 1) ans++;
                    prev = temp; cnt = 1;
                }
            }
            i++;
        }
        if(cnt > 1) ans++;
        return ans;
    }
};