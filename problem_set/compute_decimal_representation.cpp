class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        string s = to_string(n); n = s.size();
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            string temp(n - i, '0');
            temp[0] = s[i];
            int k = stoi(temp);
            if(k) ans.push_back(k);
        }
        return ans;
    }
};