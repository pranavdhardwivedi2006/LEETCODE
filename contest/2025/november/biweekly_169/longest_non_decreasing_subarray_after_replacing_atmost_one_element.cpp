#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        int k = nums[n-1], i = n - 1;
        vector<int> arr(n); 
        while(i >= 0) {
            if(nums[i] <= k) arr[i] = ++cnt;
            else arr[i] = cnt = 1;
            k = nums[i--];
        } i = 0; cnt = 0; int ans = 0;
        while(i < n) {
            if(i == n - 1) {
                ans = max(ans, ++cnt);
                break;
            }
            int left = -1e9, right = 1e9;
            if(i > 0) left = nums[i-1];
            if(i + 1 < n) right = nums[i+1];
            if(nums[i] >= left) cnt++;
            else cnt = 1;
            if((right >= left) || (i + 2 < n && nums[i+2] >= nums[i])) {
                ans = max(ans, cnt + arr[i+1]);
            }
            ans = max(cnt + 1, ans);
            if(i) ans = max(ans, arr[i+1] + 1);
            i++;
        }  
        return ans;
    }
};