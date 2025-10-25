class Solution {
public:
    string lexSmallest(string s) {
        int n = s.size(); string ans = s;
        for(int i = 0; i < n; i++) {
            string temp(s.begin(), s.end());
            reverse(temp.begin() + i, temp.end());
            ans = min(ans, temp); 
            string temp2(s.begin(), s.end());
            reverse(temp2.begin(), temp2.begin() + i + 1);
            ans = min(ans, temp2);
        }
        return ans;
    }
};