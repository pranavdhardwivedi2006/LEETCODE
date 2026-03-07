class Solution {
private:
    pair<int, int> e(vector<int>& a) {
        if(a.empty()) return {0, 0};
        int mini = a[0], maxi = a.back();
        if(mini % 2 == 0) mini++;
        if(maxi % 2 == 0) maxi--;
        return {mini, maxi};
    } 
    pair<int, int> o(vector<int>& a) {
        if(a.empty()) return {0, 0};
        int mini = a[0], maxi = a.back();
        if(mini & 1) mini++;
        if(maxi & 1) maxi--;
        return {mini, maxi};
    } 
    int comp(pair<int, int>& a, pair<int, int>& b) { 
        if(a.first > a.second) {
            int mini = max(b.second, a.second) - min(a.second, b.first);
            int maxi = max(b.second, a.first) - min(a.first, b.first);
            return min(maxi, mini);
        }
        if(b.first > b.second) return comp(b, a);
        int mini = min({a.first, a.second, b.first, b.second});
        int maxi = max({a.first, a.second, b.first, b.second});
        return maxi - mini;
    }
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        vector<int> a, b, ans1(2), ans2(2);
        int n = nums.size(); if(n == 1) return {0, 0};
        for(int i = 0; i < n; i++) {
            if(i & 1) a.push_back(nums[i]);
            else b.push_back(nums[i]);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int o1 = 0, o2 = 0, e1 = 0, e2 = 0;
        for(auto& it : a) (it & 1) ? o1++ : e1++;
        for(auto& it : b) (it & 1) ? o2++ : e2++;
        ans1[0] = o1 + e2; ans2[0] = o2 + e1;
        pair<int, int> t1, t2;
        t1 = o(a); t2 = e(b); ans1[1] = comp(t1, t2);
        t1 = o(b); t2 = e(a); ans2[1] = comp(t1, t2);
        return min(ans1, ans2);
    }
};