class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX, n = words.size();
        for(int i = startIndex; i < startIndex + n; i++) {
            if(words[i%n] == target) {
                ans = min(ans, i - startIndex);
                break;
            }
        }
        for(int i = startIndex; i > startIndex - n; i--) {
            if(words[(i+n)%n] == target) {
                ans = min(ans, startIndex - i);
                break;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};