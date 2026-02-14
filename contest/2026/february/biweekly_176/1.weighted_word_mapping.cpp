class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto it : words) {
            int x = 0;
            for(char c : it) x += weights[c-'a'];
            ans += 25 - (x % 26) + 'a';
        }
        return ans;
    }
};