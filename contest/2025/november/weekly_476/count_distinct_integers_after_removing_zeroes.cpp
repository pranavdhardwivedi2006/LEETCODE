class Solution {
public:
    long long countDistinct(long long n) {
        long long ans = 0, x = 1;
        string s = to_string(n);
        n = s.size(); int i = 0;
        vector<long long> nums(n); 
        long long sum = nums[0] = 0;
        for(int i = 1; i < n; i++) sum += nums[i] += x *= 9; 
        reverse(nums.begin(), nums.end());
        while(i < n) {
            if(i == n - 1) ans += s[i] - '0';
            else if(s[i] != '0') ans += (s[i] - '1') * nums[i];
            else break;
            i++;
        }
        return ans + sum;
    }
};