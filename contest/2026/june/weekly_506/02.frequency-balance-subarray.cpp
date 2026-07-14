class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mpp, freq;
            for(int j = i; j < n; j++) {
                mpp[nums[j]]++;
                int k = mpp[nums[j]];
                if(k > 1) {
                    if(freq[k-1] == 1) freq.erase(k-1);
                    else freq[k-1]--;
                }
                freq[k]++;
                if(mpp.size() == 1) ans = max(ans, j - i + 1);
                if(freq.size() == 2) {
                    auto it = freq.begin();
                    auto it1 = freq.begin(); it1++;
                    int x = min(it -> first, it1 -> first);
                    int y = max(it -> first, it1 -> first);
                    if(x * 2 == y) ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};