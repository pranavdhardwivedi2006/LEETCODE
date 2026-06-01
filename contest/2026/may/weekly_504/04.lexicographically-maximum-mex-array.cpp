class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> ans, freq(maxi + 2), temp(maxi + 2);
        int mex = 0, i = 0; vector<int> modified;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            if(mex == nums[i]) while(freq[mex]) mex++;
        }        
        while(i < n) {
            int tmex = 0, curr = mex;
            ans.push_back(mex);
            while(i < n) {
                temp[nums[i]]++;
                modified.push_back(nums[i]);
                if(tmex == nums[i]) {
                    while(temp[tmex]) tmex++;
                }
                freq[nums[i]]--;
                if(!freq[nums[i]] && nums[i] < curr) curr = nums[i];
                i++;
                if(tmex == mex) break;
            }
            for(int idx : modified) {
                temp[idx] = 0;
            }
            modified.clear();
            mex = curr;
        }
        return ans;
    }
};