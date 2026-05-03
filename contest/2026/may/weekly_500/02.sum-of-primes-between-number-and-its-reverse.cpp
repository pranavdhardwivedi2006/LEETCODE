class Solution {
bool is_prime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
public:
    int sumOfPrimesInRange(int n) {
        int rev = 0, temp = n, ans = 0;
        while(temp) {
            rev = rev * 10 + temp % 10;
            temp /= 10;
        }
        if(rev < n) swap(n, rev);
        for(int i = n; i <= rev; i++) {
            if(is_prime(i)) ans += i;
        }
        return ans;
    }
};