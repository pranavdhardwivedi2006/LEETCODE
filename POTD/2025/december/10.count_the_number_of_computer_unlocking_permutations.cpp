class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int cnt = 0, n = complexity.size();
        for(auto it : complexity) if(it <= complexity[0]) cnt++;
        if(cnt > 1) return 0;
        long long ans = 1;
        for(int i = 1; i < n; i++) {
            ans = (ans * (n - i)) % 1000000007;
        }
        return ans;
    }
};