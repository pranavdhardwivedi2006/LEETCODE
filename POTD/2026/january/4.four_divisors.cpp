class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) {
            int curr = 0, div = 0;
            for(int i = 1; i * i <= it; i++) {
                if(it % i == 0) {
                    if(i * i == it) {
                        div++;
                        curr += i;
                    }
                    else {
                        div += 2;
                        curr += i + it / i;
                    }
                }
                if(div > 4) break ;
            }
            if(div == 4) sum += curr;
        }
        return sum;
    }
};