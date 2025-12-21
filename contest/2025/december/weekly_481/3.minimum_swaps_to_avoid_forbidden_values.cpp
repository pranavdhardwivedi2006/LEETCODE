#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        map<int, set<int>> mpp; map<int, int> sim;
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == forbidden[i]) sim[nums[i]]++;
            else mpp[nums[i]].insert(forbidden[i]);
        }
        multimap<int, int, greater<int>> sim2;
        for(auto [u, v] : sim) sim2.insert({v, u});
        while(sim2.size() > 1) {
            auto it = sim2.begin();
            auto it1 = sim2.begin(); it1++;
            if(it -> first != it1 -> first) sim2.insert({it -> first - it1 -> first, it -> second});
            for(int i = 0; i < it1 -> first; i++) mpp[it->second].insert(it1->second);
            ans += it1 -> first;
            sim2.erase(it);
            sim2.erase(it1);
        }
        for(auto [u, x] : sim2) {
            int q = u;
            while(q--) {
                auto l = mpp.begin();
                auto r = mpp.rbegin();
                bool complete = false;
                cout << mpp.size() << endl;
                if(l -> first == x && r -> first == x) return -1;
                while((l != mpp.end() && l -> first < x) || (r != mpp.rend() && r -> first > x)) {
                    if(l != mpp.end() && l -> first < x) {
                        auto l1 = l -> second.begin();
                        auto r1 = l -> second.rbegin();
                        if(*l1 != x) {
                            complete = true;
                            mpp[x].insert(*l1);
                            l -> second.erase(l1); 
                            l -> second.insert(x);
                            break;
                        }
                        else if(*r1 != x) {
                            complete = true;
                            mpp[x].insert(*r1);
                            l -> second.erase(*r1); 
                            l -> second.insert(x);
                            break;
                        }
                        else if(l != mpp.end()) l++;
                    }
                    if(r != mpp.rend() && r -> first > x) {
                        auto l1 = r -> second.begin();
                        auto r1 = r -> second.rbegin();
                        if(*l1 != x) {
                            complete = true;
                            mpp[x].insert(*l1);
                            r -> second.erase(l1); 
                            r -> second.insert(x);
                            break;
                        }
                        else if(*r1 != x) {
                            complete = true;
                            mpp[x].insert(*r1);
                            r -> second.erase(*r1); 
                            r -> second.insert(x);
                            break;
                        }
                        else if(r != mpp.rend()) r++;
                    }
                }
                if(!complete) return -1;
                ans++;
            }
        }
        return ans;
    }
};