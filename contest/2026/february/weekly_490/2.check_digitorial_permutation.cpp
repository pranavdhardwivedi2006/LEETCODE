class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> arr(10, 1);
        for(int i = 1; i < 10; i++) arr[i] = i * arr[i-1];
        long long sum = 0, copy = n;
        while(copy) {
            sum += arr[copy % 10];
            copy /= 10;
        }
        string s = to_string(sum), s1 = to_string(n);
        sort(s.begin(), s.end());
        sort(s1.begin(), s1.end());
        return s == s1;
    }
};