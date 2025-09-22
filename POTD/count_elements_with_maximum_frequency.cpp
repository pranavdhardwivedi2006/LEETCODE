class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mpp; int maxi = 0, cnt = 0;
        for(auto& it : nums) mpp[it]++;
        for(auto& it : mpp) maxi = max(maxi, it.second);
        for(auto& it : mpp) if(maxi == it.second) cnt++;
        return cnt * maxi;
    }
};