class Solution {
int n; 
vector<int> num;
array<long long, 2> dp[16][11][11][2][2];
int digit(long long temp) {
    int cnt = 0;
    while(temp) {
        cnt++; temp /= 10;
    }
    return cnt;
}
void fill(long long temp) {
    n = digit(temp);
    num.assign(n, 0);
    memset(dp, -1, sizeof(dp));
    for(int i = n - 1; i >= 0; i--) {
        num[i] = temp % 10;
        temp /= 10;
    }
}
array<long long, 2> rec(int index, int slast, int last, int free, int started) {
    if(index >= n) return {0, 1};
    if(dp[index][slast][last][free][started][0] != -1) return dp[index][slast][last][free][started];
    long long total_waves = 0;
    long long total_ways = 0;
    int limit = free ? 9 : num[index];
    for(int i = 0; i <= limit; i++) {
        int new_free = free || (i < num[index]);
        int new_started = started || (i > 0);         
        array<long long, 2> res = {0, 0};
        if(!started) {
            if(i == 0) res = rec(index + 1, 10, 10, new_free, new_started);
            else res = rec(index + 1, 10, i, new_free, new_started);
        } else if(slast == 10) {
            res = rec(index + 1, last, i, new_free, new_started);
        } else {
            res = rec(index + 1, last, i, new_free, new_started);
            bool is_wave = (last > slast && last > i) || (last < slast && last < i);
            if(is_wave) total_waves += res[1];
        }
        total_waves += res[0];
        total_ways += res[1];
    }
    return dp[index][slast][last][free][started] = {total_waves, total_ways};
}
long long calc(long long limit) {
    if(limit <= 100) return 0;
    fill(limit);
    return rec(0, 10, 10, 0, 0)[0];
}
public:
    long long totalWaviness(long long num1, long long num2) {
        return calc(num2) - calc(num1 - 1);
    }
};