class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> arr;
        vector<int> brr;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < pivot) arr.push_back(nums[i]);
            else if(nums[i] > pivot) brr.push_back(nums[i]);
            else cnt++;
        }
        int k = arr.size() + cnt;
        for(int i=0;i<nums.size();i++){
            if(i < arr.size()) nums[i] = arr[i];
            else if(i < k) nums[i] = pivot;
            else nums[i] = brr[i-k];
        }
        return nums;
    }
};