#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(string s) {
        int cnt = 0, ans = 0;
        int i = 0, n = s.size();
        while(i < n) {
            if(s[i] == '1') cnt++, i++;
            else {
                ans += cnt;
                while(i < n && s[i] == '0') i++; 
            }
        }
        return ans;
    }
};