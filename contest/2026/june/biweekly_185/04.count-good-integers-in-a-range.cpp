class Solution {
int k;
long long dp[16][11][2][2];
vector<int> to_array(long long num) {
    vector<int> arr;
    while(num) {
        arr.push_back(num % 10);
        num /= 10;
    }
    reverse(arr.begin(), arr.end());
    return arr;
}

long long rec(int index, int prev, bool free, bool zero, vector<int>& arr) {
    if(index == arr.size()) return 1;
    if(dp[index][prev][free][zero] != -1) return dp[index][prev][free][zero];
    long long ans = 0; 
    if(free) {
        for(int i = 0; i <= 9; i++) {
            if(zero && !i) {
                ans += rec(index + 1, prev, 1, 1, arr);
            } else if(prev == 10 || abs(i - prev) <= k) { 
                ans += rec(index + 1, i, 1, 0, arr);
            }
        }
    } else {
        for(int i = 0; i < arr[index]; i++) {
            if(zero && !i) {
                ans += rec(index + 1, prev, 1, 1, arr);
            } else if(prev == 10 || abs(i - prev) <= k) { 
                ans += rec(index + 1, i, 1, 0, arr);
            }
        }
        if(zero && arr[index] == 0) ans += rec(index + 1, prev, 0, 1, arr);
        else if(prev == 10 || zero || abs(arr[index] - prev) <= k) ans += rec(index + 1, arr[index], 0, 0, arr);
    }
    return dp[index][prev][free][zero] = ans;
}
public:
    long long goodIntegers(long long l, long long r, int k) {
        this -> k = k;
        memset(dp, -1, sizeof(dp));
        vector<int> temp = to_array(r);
        long long ans = rec(0, 10, 0, 1, temp);
        memset(dp, -1, sizeof(dp));
        temp = to_array(l - 1);
        return ans - rec(0, 10, 0, 1, temp);
    }
};