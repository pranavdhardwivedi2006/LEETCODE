class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        map<string, int> dict;
        string s;
        for(auto& it : chunks) s += it;
        int n = s.size(), i = 0;
        while(i < n) {
            string temp;
            while(i < n && ((s[i] >= 'a' && s[i] <= 'z') || s[i] == '-')) {
                if(s[i] == '-' && (temp.size() == 0 || temp.back() == '-')) break;
                temp += s[i++];
            }
            while(temp.size() && temp.back() == '-') temp.pop_back();
            dict[temp]++;
            i++;
        }
        vector<int> ans;
        for(auto& it : queries) {
            ans.push_back(dict[it]);
        }
        return ans;
    }
};