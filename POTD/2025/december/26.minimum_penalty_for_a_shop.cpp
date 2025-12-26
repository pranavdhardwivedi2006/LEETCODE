class Solution {
public:
    int bestClosingTime(string customers) {
        int curr = 0, n = customers.size();
        for(auto& it : customers) if(it == 'N') curr++;
        int hour = n, mini = curr;
        for(int i = n - 1; i >= 0; i--) {
            customers[i] == 'N' ? curr-- : curr++; 
            if(mini >= curr) {
                mini = curr;
                hour = i;
            }
        }
        return hour;
    }
};