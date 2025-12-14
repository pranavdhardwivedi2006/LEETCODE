#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, n = s.size(), cnt = 0;
        string ans;
        while(i < n && s[i] != ' ') {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt++;
            ans += s[i]; i++;
        } i++; ans += " ";
        while(i < n) {
            int k = i, cur = 0;
            while(i < n && s[i] != ' ') {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cur++;
                ans += s[i]; i++;
            }
            if(cur == cnt) reverse(ans.begin() + k, ans.end());
            ans += " "; i++;
        } 
        ans.pop_back();
        return ans;
    }
};