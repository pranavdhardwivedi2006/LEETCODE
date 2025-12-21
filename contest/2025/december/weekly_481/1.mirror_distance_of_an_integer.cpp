#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mirrorDistance(int n) {
        int x = n, m = 0;
        while(x) {
            m = m * 10 + x % 10;
            x /= 10;
        }
        return abs(m - n);
    }
};