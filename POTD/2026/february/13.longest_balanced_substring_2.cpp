class Solution {
private:
    int one(string& s, char c) {
        int i = 0, n = s.size();
        int cnt = 0, ans = 0;
        while(i < n) {
            while(i < n && s[i] == c) i++, cnt++;
            ans = max(ans, cnt); cnt = 0; i++;
        }
        return ans;
    }
    int two(string& s, char a, char b, char c) {
        int i = 0, n = s.size(), ans = 0;
        while(i < n) {
            int x = 0, y = 0;
            map<int, int> mpp; mpp[0] = i - 1;
            while(i < n && s[i] != c) {
                s[i] == a ? x++ : y++;
                if(mpp.count(x-y)) ans = max(ans, i - mpp[x-y]);
                else mpp[x-y] = i; i++;
            }
            i++;
        }
        return ans;
    }
    int three(string& s) {
        map<pair<int, int>, int> mpp; 
        int n = s.size(); mpp[{0, 0}] = -1;
        int a = 0, b = 0, c = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            s[i] == 'a' ? a++ : s[i] == 'b' ? b++ : c++;
            auto it = make_pair(a - b, b - c);
            if(mpp.count(it)) ans = max(ans, i - mpp[it]);
            else mpp[it] = i;
        }
        return ans;
    }
public:
    int longestBalanced(string s) {
        int ans = three(s); ans = max(ans, two(s, 'a', 'b', 'c'));
        ans = max(ans, two(s, 'a', 'c', 'b'));
        ans = max(ans, two(s, 'c', 'b', 'a'));
        ans = max({ans, one(s, 'a'), one(s, 'b'), one(s, 'c')});
        return ans;
    }
};