class Solution {
void forward(vector<int>& nums, vector<int>& forward) {
    int n = nums.size(); forward[1] = 1;
    for(int i = 1; i < n - 1; i++) {
        if(nums[i] - nums[i-1] > nums[i+1] - nums[i]) forward[i+1] = 1;
        else forward[i+1] = nums[i+1] - nums[i];
    }
    for(int i = 1; i < n; i++) forward[i] += forward[i-1];
}
void backward(vector<int>& nums, vector<int>& backward) {
    int n = nums.size(); backward[n-2] = 1;
    for(int i = 1; i < n - 1; i++) {
        if(nums[i] - nums[i-1] <= nums[i+1] - nums[i]) backward[i-1] = 1;
        else backward[i-1] = nums[i] - nums[i-1];
    }
    for(int i = n - 2; i >= 0; i--) backward[i] += backward[i+1];
}
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), i = 0;
        vector<int> forward(n, 0), backward(n, 0);
        this -> forward(nums, forward);
        this -> backward(nums, backward);
        vector<int> ans(queries.size());
        for(auto& q : queries) {
            if(q[0] < q[1]) ans[i++] = forward[q[1]] - forward[q[0]];
            else ans[i++] = backward[q[1]] - backward[q[0]];
        }
        return ans;
    }
};