class Solution {
int MOD = 1e9 + 7;
int pow(int x, int p) {
    if(p == 0) return 1;
    long long num = pow(x, p / 2);
    num = (num * num) % MOD;
    if(p & 1) num = (num * x) % MOD;
    return num;
}
long long inv() {
    return pow(9, MOD - 2);
}
public:
    int sumOfNumbers(int l, int r, int k) {
        int comb = pow(r - l + 1, k - 1);
        int sum = r * (r + 1) / 2 - l * (l - 1) / 2;
        sum = (1LL * comb * sum) % MOD;
        int x = ((pow(10, k) - 1 + MOD) % MOD * inv()) % MOD; 
        return (1LL * x * sum) % MOD;
    }
};