class TaskManager {
map<int, map<int, int>> mpp;
unordered_map<int, int> mpp2;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto& it : tasks) {
            mpp[it[2]][it[1]] = it[0];
            mpp2[it[1]] = it[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mpp[priority][taskId] = userId;
        mpp2[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        int prior = mpp2[taskId];
        mpp2[taskId] = newPriority;
        int userId = mpp[prior][taskId];
        mpp[prior].erase(taskId);
        if(mpp[prior].size() == 0) mpp.erase(prior);
        mpp[newPriority][taskId] = userId;
    }
    
    void rmv(int taskId) {
        int prior = mpp2[taskId];
        mpp2.erase(taskId);
        mpp[prior].erase(taskId);
        if(!mpp[prior].size()) mpp.erase(prior);
    }
    
    int execTop() {
        if(!mpp.size()) return -1;
        auto it = mpp.end(); it--;
        auto it2 = it->second.end(); it2--;
        int ans = it2->second;
        int first = it->first;
        mpp[first].erase(it2->first);
        if(!mpp[first].size()) mpp.erase(first);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */