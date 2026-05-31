class Solution {
public:
    int numberOfSpecialChars(string word) {
        int trk[128] = {0};
        for(auto it : word) trk[it]++;
        int ans = 0, diff = 'A' - 'a';
        for(char c = 'A'; c <= 'Z'; c++) {
            bool found = false;
            char temp = c - diff;
            for(int i = 0; i < word.size(); i++) {
                if(word[i] == c) {
                    if(!trk[temp] && found) {
                        ans++;
                    }
                    break;
                } else if(word[i] == temp) {
                    found = true;
                    trk[temp]--;
                }
            }
        }
        return ans;
    }
};