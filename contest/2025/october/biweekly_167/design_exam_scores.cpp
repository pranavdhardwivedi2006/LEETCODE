class ExamTracker {
vector<long long> trk; map<int, int> mpp;
public:
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        int n = trk.size();
        if(n == 0) trk.push_back(0), n++;
        mpp[time] = n;
        trk.push_back(trk.back() + score);
    }
    
    long long totalScore(int startTime, int endTime) {
        auto x = mpp.lower_bound(startTime);
        auto y = mpp.upper_bound(endTime); y--;
        if(x == mpp.end() || x -> first > endTime) return 0;
        return trk[y->second] - trk[x->second-1];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */