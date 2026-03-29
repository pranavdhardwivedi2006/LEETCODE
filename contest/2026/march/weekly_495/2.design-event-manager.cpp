class EventManager {
map<int, set<int>, greater<int>> mp1;
map<int, int> mp2;
public:
    EventManager(vector<vector<int>>& events) {
        for(auto& it : events) {
            mp1[it[1]].insert(it[0]);
            mp2[it[0]] = it[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldP = mp2[eventId];
        mp1[oldP].erase(eventId); 
        if(mp1[oldP].empty()) mp1.erase(oldP);
        mp2[eventId] = newPriority;
        mp1[newPriority].insert(eventId);
    }
    
    int pollHighest() {
        if(mp1.empty()) return -1;
        auto& [u, v] = *mp1.begin();
        auto& x = *v.begin(); int ans = x;
        mp2.erase(x); v.erase(x);
        if(v.empty()) mp1.erase(u);
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */