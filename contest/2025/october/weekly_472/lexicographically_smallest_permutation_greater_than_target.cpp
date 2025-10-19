class Solution {
string ans;
private:
    void find(vector<int> trk, string temp, char c) {
        bool flag = false;
        for(int i = c - 'a' + 1; i < 26; i++) {
            if(trk[i]) {
                flag = true; trk[i]--;
                temp += 'a' + i;
                break;
            }
        }
        if(!flag) return ;
        for(int i = 0; i < 26; i++) {
            string temp2(trk[i], 'a' + i);
            temp += temp2;
        }
        ans = temp;
    } 
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> trk(26, 0); string curr;
        for(auto it : s) trk[it-'a']++;
        for(char c : target) {
            find(trk, curr, c);
            if(trk[c-'a']) curr += c, trk[c-'a']--;
            else break ;
        }
        if(curr > target) return min(curr, ans);
        return ans;
    }
};