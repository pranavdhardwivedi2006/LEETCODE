class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        vector<int> trk(3, 0);
        int j = 0;
        int i = 0;
        while(j < s.size()) {
            trk[s[j++] - 'a']++;
            if(trk[0] && trk[1] && trk[2]) {
                while(trk[0] && trk[1] && trk[2]){
                    cnt += s.size() - j + 1;
                    trk[s[i++] - 'a']--;
                }
            }
        }
        return cnt;
    }
};