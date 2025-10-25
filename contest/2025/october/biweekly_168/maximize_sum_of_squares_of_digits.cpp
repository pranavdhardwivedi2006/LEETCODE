class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9 * num < sum) return "";
        string ans(sum / 9, '9'); 
        if(sum % 9) ans += sum % 9 + '0'; 
        int k = num - ans.size();
        string temp(k, '0');
        return ans + temp;
    }
};