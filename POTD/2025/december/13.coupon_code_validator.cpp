#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size(); vector<string> e, g, p, r;
        for(int i = 0; i < n; i++) {
            if(code[i] == "" || !isActive[i]) continue;
            bool is = false;
            for(auto& it : code[i]) {
                if(isalnum(it) || it == '_') continue ;
                is = true; break;
            } 
            if(is) continue;
            string& s = businessLine[i];
            if(s == "electronics") e.push_back(code[i]);
            else if(s == "grocery") g.push_back(code[i]);
            else if(s == "pharmacy") p.push_back(code[i]);
            else if(s == "restaurant") r.push_back(code[i]);
        }
        sort(e.begin(), e.end()); sort(g.begin(), g.end());
        sort(p.begin(), p.end()); sort(r.begin(), r.end());
        for(auto it : g) e.push_back(it);
        for(auto it : p) e.push_back(it);
        for(auto it : r) e.push_back(it);
        return e;
    }
};