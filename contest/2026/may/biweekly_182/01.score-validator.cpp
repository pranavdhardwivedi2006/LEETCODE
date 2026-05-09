class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int sc = 0, counter = 0;
        for(auto it : events) {
            if(counter == 10) break;
            if(it == "WD" || it == "NB") sc += 1;
            else if(it == "W") counter++;
            else sc += stoi(it);
        }
        return {sc, counter};
    }
};