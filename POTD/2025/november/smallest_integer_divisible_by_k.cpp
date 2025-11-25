class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0) return -1;
        int num = 1, ans = 1;
        vector<bool> trk(k, 0);
        while(k) { 
            if(num % k == 0) return ans;
            num %= k; if(trk[num]) return -1;
            trk[num] = true;
            while(num < k) {
                num = num * 10 + 1;
                ans++;
            }
        }
        return -1;
    }
};