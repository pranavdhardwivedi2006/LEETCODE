#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n = balance.size(), j = -1;
        long long sum = 0, res = 0;
        for (int i = 0; i < n; i++) {
            sum += balance[i];
            if (balance[i] < 0) {
                j = i;
            }
        }
        if(j == -1) return 0;
        if(sum < 0) return -1;
        for(int i = 1; balance[j] < 0; i++) {
            long long cur = balance[(j + i) % n] + balance[(j - i % n + n) % n];
            res += min(-1LL * balance[j], cur) * i;
            balance[j] += cur;
        }
        return res;
    }
};