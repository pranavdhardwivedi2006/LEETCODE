class Solution {
private:
    int ref(int num) {
        int r = 0;
        while(num) {
            r = (r << 1) | (num & 1);
            num >>= 1;
        }
        return r;
    }
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> arr;
        for(auto& it : nums) {
            arr.push_back({ref(it), it});
        }
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); i++) nums[i] = arr[i].second;
        return nums;
    }
};