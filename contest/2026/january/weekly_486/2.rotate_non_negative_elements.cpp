class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> pos;
        for(auto it : nums) if(it >= 0)  pos.push_back(it);
        int x = pos.size(), i = 0; vector<int> ans(x);
        if(x == 0) return nums; k %= x;
        for(int i = 0; i < x; i++) {
            ans[(i-k+x)%x] = pos[i];
        }
        for(auto& it : nums) if(it >= 0)  it = ans[i++];
        return nums;
    }
};