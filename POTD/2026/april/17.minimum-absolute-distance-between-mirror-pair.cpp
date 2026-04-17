class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        map<int, int> mpp; 
        int n = nums.size(), ans = INT_MAX;
        for(int i = n - 1; i >= 0; i--) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            int rev = stoi(s);
            if(mpp.find(rev) != mpp.end()) ans = min(ans, mpp[rev] - i);
            mpp[nums[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};