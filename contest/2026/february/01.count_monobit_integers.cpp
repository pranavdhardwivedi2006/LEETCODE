class Solution {
public:
    int countMonobit(int n) {
        int cnt = 0, x = 0;
        while(x <= n) {
            cnt++;
            x <<= 1; x += 1;
        }
        return cnt;
    }
};