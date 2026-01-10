class Solution {
public:
    long long minimumCost(string s, string t, int flipCost, int swapCost, int crossCost) {
        long long z = 0, o = 0, ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) continue ;
            s[i] == '0' ? z++ : o++;
        }
        if(z > o) swap(z, o); o -= z;
        if(swapCost < 2 * flipCost) ans = z * swapCost;
        else ans = 2 * z * flipCost; 
        if(o & 1) ans += flipCost, o--;
        if(crossCost + swapCost < 2 * flipCost) {
            ans += o / 2 * (crossCost + swapCost);
        }
        else ans += o * flipCost;
        return ans;
    }
};