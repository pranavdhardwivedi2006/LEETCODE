class Fancy {
private:
    int MOD = 1e9 + 7;
    vector<int> arr;
    long long m = 1, a = 0;

    long long power(long long b, long long e) {
        long long res = 1; b %= MOD;
        while (e > 0) {
            if(e & 1) res = (res * b) % MOD;
            b = (b * b) % MOD; e /= 2;
        }
        return res;
    }

    long long inv(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {}

    void append(int val) { 
        long long x = (val - a) % MOD;
        if (x < 0) x += MOD;
        x = x * inv(m) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        a = (a + inc) % MOD;
    }

    void multAll(int x) {
        a = a * x % MOD;
        m = m * x % MOD;
    }

    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        return (arr[idx] * m + a) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */