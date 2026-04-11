class Solution {
bool is_prime(vector<int>& prime, int num) {
    int l = 0, r = prime.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(prime[mid] == num) return true;
        if(prime[mid] < num) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}
int next(vector<int>& prime, int num) {
    int l = 0, r = prime.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(prime[mid] < num) l = mid + 1;
        else r = mid - 1;
    }
    return prime[l];
}
public:
    int minOperations(vector<int>& nums) {
        vector<int> prime;
        vector<bool> sieve(200000, true);
        for(int i = 2; i * i < 200000; i++) {
            if(sieve[i]) {
                for(int j = i * i; j < 200000; j += i) {
                    sieve[j] = false;
                }
            }
        }
        for(int i = 2; i < 200000; i++) if(sieve[i]) prime.push_back(i);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i & 1) {
                if(is_prime(prime, nums[i])) {
                    if(nums[i] == 2) ans += 2;
                    else ans++;
                }
            } else {
                ans += next(prime, nums[i]) - nums[i];
            }
        }
        return ans;
    }
};