#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int a=n;
        while(n>>=1) a^=n;
        return a;
    }
};