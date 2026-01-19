class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size(); vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) arr[i] = {costs[i], capacity[i]};
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            capacity[i] = arr[i].second;
            costs[i] = arr[i].first;
        }
        set<pair<int, int>> st;
        int l = 0, r =  n - 1, ans = 0;
        for(int i = 0; i < n; i++) st.insert({capacity[i], i});
        while(l < n) {
            if(l <= r) st.erase({capacity[l], l});
            int cost = budget - costs[l] - 1, curr = 0;
            if(costs[l] < budget) curr = capacity[l];
            while(r >= 0 && costs[r] > cost) {
                st.erase({capacity[r], r});
                r--;
            }
            auto it = st.rbegin();
            if(it != st.rend()) curr += (it -> first);
            ans = max(ans, curr);
            if(l <= r) st.insert({capacity[l], l}); l++;
        }
        return ans;
    }
};