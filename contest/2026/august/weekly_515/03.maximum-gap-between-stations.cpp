class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> prefix(m), suffix(m);
        int j = 0;
        for(int i = 1; i <= n; i++) {
            while(j < m && skill[i-1] != station[j]) prefix[j++] = i - 1;
            prefix[j++] = i;
        }
        j = m - 1;
        for(int i = n; i > 0; i--) {
            while(j >= 0 && skill[i-1] != station[j]) suffix[j--] = n - i;
            suffix[j--] = n - i + 1;
        }
        int l = 0, r = 0,ans = 0;
        while(!prefix[l]) l++;
        while(!suffix[r]) r++;
        while(l < m && r < m) {
            int remain = n - prefix[l];
            if(!prefix[l] || !remain) break;
            while(r < m && suffix[r] >= remain) r++;
            ans = max(ans, r - l - 1);
            l++;
        }
        return ans;
    }
};