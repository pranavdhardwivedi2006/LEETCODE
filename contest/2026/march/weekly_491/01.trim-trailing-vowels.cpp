class Solution {
bool is(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}
public:
    string trimTrailingVowels(string s) {
        while(!s.empty() && is(s.back())) s.pop_back();
        return s;
    }
};