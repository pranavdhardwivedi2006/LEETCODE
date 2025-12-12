class Solution {
public:
    int largestPrime(int n) {
        int ans = 0, curr = 0;
        vector<bool> prime(n + 1, true);
        for(int i = 2; i * i <= n; i++) {
            if(prime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        for(int i = 2; i <= n; i++) {
            if(prime[i]) curr += i;
            if(curr > n) break;
            if(prime[curr]) ans = curr;
        }
        return ans;
    }
};