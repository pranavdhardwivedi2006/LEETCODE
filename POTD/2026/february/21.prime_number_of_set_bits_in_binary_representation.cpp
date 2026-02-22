class Solution {
private:
    int prime(int n) {
        if(n == 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
    int bits(int n) {
        int cnt = 0;
        while(n) {
            if(n & 1) cnt++;
            n >>= 1;
        }
        return cnt;
    }
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left; i <= right; i++) {
            int cnt = bits(i);
            if(prime(cnt)) ans++;
        }
        return ans;
    }
};