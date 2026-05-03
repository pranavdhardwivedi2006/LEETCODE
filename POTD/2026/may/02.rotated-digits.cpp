class Solution {
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            bool found = false, other = true;
            int k = i;
            while(k) {
                int rem = k % 10; k /= 10;
                if(rem == 2 || rem == 5 || rem == 6 || rem == 9) {
                    found = true;
                }
                if(rem == 3 || rem == 4 || rem == 7) {
                    other = false;
                }
            }
            if(found & other) ans++;
        }
        return ans;
    }
};