class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start = stoi(string(1, startTime[0]) + string(1, startTime[1])) * 3600;
        start += stoi(string(1, startTime[3]) + string(1, startTime[4])) * 60;
        start += stoi(string(1, startTime[6]) + string(1, startTime[7]));
        int end = stoi(string(1, endTime[0]) + string(1, endTime[1])) * 3600;
        end += stoi(string(1, endTime[3]) + string(1, endTime[4])) * 60;
        end += stoi(string(1, endTime[6]) + string(1, endTime[7]));
        return end - start;
    }
};