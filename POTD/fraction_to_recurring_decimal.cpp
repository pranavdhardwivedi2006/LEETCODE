class Solution {
public:
    string fractionToDecimal(int num, int denom) {
        long long numerator = num, denominator = denom;
        if(!numerator) return "0";
        map<int, int> mpp; string ans;
        int first = numerator < 0 ? -1 : 1;
        int second = denominator < 0 ? -1 : 1;
        numerator = abs(numerator); 
        denominator = abs(denominator);
        ans += to_string(numerator / denominator);
        numerator %= denominator;
        if(numerator != 0) ans += ".";
        while(numerator) {
            numerator *= 10;
            while(numerator < denominator) numerator *= 10, ans += "0";
            if(mpp.find(numerator) != mpp.end()) {
                ans.insert(mpp[numerator], "(");
                ans += ")"; break;
            }
            mpp[numerator] = ans.size();
            ans += to_string(numerator / denominator);
            numerator %= denominator;
        }
        first *= second;
        if(first == -1) ans = "-" + ans;
        return ans;
    }
};