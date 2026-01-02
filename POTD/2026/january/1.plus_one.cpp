class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1, n = digits.size();
        if (i == 0) {
            if (digits[i] == 9) return {1, 0};
            else return {digits[i] + 1};
        }
        while (i > 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
                if (digits[i - 1] != 9) {
                    digits[i - 1] += 1;
                    break;
                }
            } else {
                digits[i] = digits[i] + 1;
                return digits;
            }
            i--;
        }
        if(i == 0) {
            int a = digits[digits.size() - 1];
            digits.resize(n + 1);
            i = digits.size() - 1;
            while (i > 0) {
                digits[i] = digits[i - 1];
                i--;
            }
            digits[0] = 1;
            digits[1] = 0;
        }
        return digits;
    }
};