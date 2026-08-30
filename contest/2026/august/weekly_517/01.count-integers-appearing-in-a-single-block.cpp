class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int arr[101] = {0};
        for(auto it : nums) arr[it]++;
        int prev = nums[0], cnt = 0;
        int i = 0, n = nums.size(), ans = 0;
        while(i < n) {
            prev = nums[i];
            cnt = 0;
            while(i < n && nums[i] == prev) cnt++, i++;
            if(arr[prev] == cnt) ans++;
        }
        return ans;
    }
};