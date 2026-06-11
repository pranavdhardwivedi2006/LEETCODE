class Solution {
string s;
unordered_set<string> st;
void generate(int index, char prev, int curr, int n, int k) {
    if(index >= n) {
        st.insert(s);
        return ;
    }
    s[index] = '0';
    generate(index + 1, '0', curr, n, k);
    if(curr + index <= k && prev != '1') {
        s[index] = '1';
        generate(index + 1, '1', curr + index, n, k);
    }
}
public:
    vector<string> generateValidStrings(int n, int k) {
        s.resize(n, ' ');
        generate(0, '2', 0, n, k);
        return vector<string>(st.begin(), st.end());
    }
};