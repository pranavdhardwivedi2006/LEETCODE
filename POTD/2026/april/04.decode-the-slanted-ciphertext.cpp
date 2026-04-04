class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size(); 
        int cols = n / rows; string ans;
        for(int j = 0; j < cols; j++) {
            int st = j;
            while(st < n) {
                ans += encodedText[st];
                st += cols + 1;
            }
        }
        while(!ans.empty() && ans.back() == ' ') ans.pop_back();
        return ans;
    }
};