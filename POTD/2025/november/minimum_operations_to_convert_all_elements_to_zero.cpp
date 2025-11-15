#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        stack<int> st;
        for(auto it : nums) {
            if(it == 0) {
                while(!st.empty()) {
                    int k = st.top();
                    while(!st.empty() && st.top() == k) st.pop();
                    cnt++;
                }
                continue;
            }
            while(!st.empty() && st.top() > it) {
                int k = st.top();
                while(!st.empty() && st.top() == k) st.pop();
                cnt++;
            }
            st.push(it);
        }
        while(!st.empty()) {
            int k = st.top();
            while(!st.empty() && st.top() == k) st.pop();
            cnt++;
        }
        return cnt;
    }
};