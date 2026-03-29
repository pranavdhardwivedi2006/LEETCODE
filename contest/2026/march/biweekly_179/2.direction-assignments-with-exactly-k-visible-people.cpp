class Solution {
int MOD = 1e9 + 7;
int power(int x, int y) {
    if(y == 0) return 1;
    long long mult = power(x, y / 2);
    mult = mult * mult % MOD;
    if(y & 1) mult = mult * x % MOD;
    return mult;
}

int fact(int n) {
    long long ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}
    
public:
    int countVisiblePeople(int n, int pos, int k) {
        if(n == 1) return 2; n--;
        long long x = fact(n), y = fact(k), z = fact(n - k);
        long long d1 = power(y, MOD - 2), d2 = power(z, MOD - 2);
        return 2 * x % MOD * d1 % MOD * d2 % MOD;
    }
};