class Solution {
public:
    int binaryGap(int n) {
        while(n && !(n & 1)) n >>= 1;
        int cnt = 0, ans = 0;
        while(n) {
            if(n & 1) {
                ans = max(ans, cnt);
                cnt = 1;
            }
            else cnt++; 
            n >>= 1;
        }
        return ans;
    }
};