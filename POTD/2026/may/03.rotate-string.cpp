class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return 0;
        }
        for (int i = 0; i < s.length(); i++) {
            int first = s[0];     
            s.erase(s.begin()); 
            s.push_back(first);
            if(s==goal){
                return 1;
            }
        }
        return 0;
    }
};