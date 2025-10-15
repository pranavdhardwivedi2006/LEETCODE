class Router {
int n; queue<tuple<int, int, int>> q;
unordered_map<int, int> forw; 
set<tuple<int, int, int>> trk;
unordered_map<int, vector<pair<int, int>>> mpp;
public:
    Router(int memoryLimit) {
        n = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        auto& it = mpp[destination]; 
        tuple<int, int, int> tup = {source, destination, timestamp};
        if(trk.find(tup) != trk.end()) return false;
        trk.insert(tup);
        if(q.size() == n) {
            auto [s, d, t] = q.front();
            trk.erase(q.front());
            q.pop(); mpp[d][forw[d]++] = {-1, -1};
        }
        q.push(tup);
        mpp[destination].push_back({timestamp, source});
        return true;
    }
    
    vector<int> forwardPacket() {
        if(q.empty()) return {};
        trk.erase(q.front()); auto [s, d, t] = q.front();
        q.pop(); mpp[d][forw[d]++] = {-1, -1};
        return {s, d, t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto& it = mpp[destination];
        auto l = lower_bound(it.begin() + forw[destination], it.end(), make_pair(startTime, INT_MIN));
        auto r = upper_bound(it.begin() + forw[destination], it.end(), make_pair(endTime, INT_MAX));
        return r - l;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */