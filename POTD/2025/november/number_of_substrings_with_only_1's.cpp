#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int numSub(string s) {
        int n = s.size(), i = 0;
        long long ans = 0; int MOD = 1e9 + 7;
        while(i < n) {
            long long cnt = 0;
            while(i < n && s[i] == '1') i++, cnt++;
            ans = (ans + cnt * (cnt + 1) / 2) % MOD; i++;
        }
        return ans;
    }
};