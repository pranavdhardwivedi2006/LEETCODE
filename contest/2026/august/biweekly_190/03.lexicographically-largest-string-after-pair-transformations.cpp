class Solution {
string rec(int k) {
    if(k == 0) return "";
    int l = 0, r = 25;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if((1 << mid) > k) r = mid - 1;
        else l = mid + 1;
    }
    char c = 'a' + r;
    return c + rec(k - (1 << r));
}
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(auto it : nums) {
            ans.push_back(rec(it));
        }
        return ans;
    }
};