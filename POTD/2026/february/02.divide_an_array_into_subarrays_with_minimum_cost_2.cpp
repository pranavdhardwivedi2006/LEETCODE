class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        set<pair<int, int>> st, valid; k--;
        long long mini = LLONG_MAX, cost = 0;
        int i = 1, n = nums.size(), prev = 1;
        while(st.size() < k) {
            st.insert({nums[i], i});
            cost += nums[i++];
        }
        mini = min(mini, cost);
        while(i < n) {
            if(prev + dist < i) {
                auto it = make_pair(nums[prev], prev);
                if(st.count(it)) {
                    st.erase(it);
                    cost -= nums[prev];
                }
                else valid.erase(it);
                prev++;
            } 
            st.insert({nums[i], i});
            cost += nums[i];
            while(st.size() > k) {
                auto it = *st.rbegin();
                cost -= it.first;
                valid.insert(it); st.erase(it);
            }
            while(!valid.empty()) {
                auto it1 = *st.rbegin();
                auto it2 = *valid.begin();
                if(it1.first <= it2.first) break;
                cost += it2.first - it1.first;
                st.erase(it1); valid.insert(it1); 
                st.insert(it2); valid.erase(it2);
            }
            mini = min(mini, cost); i++;
        }
        return mini + nums[0];
    }
};
