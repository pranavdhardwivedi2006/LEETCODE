class Solution {
public:
    string smallestPalindrome(string s) {
        int arr[26] = {0}, n = s.size(), j = 0;
        for(int i = 0; i < n / 2; i++) {
            arr[s[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            while(arr[i]--) {
                s[j] = s[n-j-1] = 'a' + i;
                j++;
            }
        }
        return s;
    }
};