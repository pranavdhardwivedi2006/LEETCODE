class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        int ans = 0, curr = 0;
        for(auto& it : capacity) {
            curr += it; ans++;
            if(curr >= sum) return ans;
        }
        return ans;
    }
};