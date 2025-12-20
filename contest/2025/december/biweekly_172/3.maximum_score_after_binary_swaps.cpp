#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        int n = s.size(), i = 0, cnt = 0;
        priority_queue<int> pq; long long ans = 0;
        while(i < n) {
            if(s[i] == '0') {
                while(cnt > 0) {
                    ans += pq.top(); cnt--;
                    pq.pop();
                }
            }
            else cnt++;
            pq.push(nums[i]); i++;
        } 
        while(cnt > 0) {
            ans += pq.top(); cnt--;
            pq.pop();
        }
        return ans;
    }
};