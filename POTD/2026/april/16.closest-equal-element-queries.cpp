class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        } 
        for(int i = 0; i < queries.size(); i++){
            int t = nums[queries[i]];
            if(mpp[t].size() < 2) ans.push_back(-1);
            else {
                int l = 0, r = mpp[t].size() - 1, mid = 0;
                while(l <= r){
                    mid = l + (r - l) / 2;
                    if(mpp[t][mid] == queries[i]) break;
                    else if(mpp[t][mid] < queries[i]) l = mid + 1;
                    else r = mid - 1;
                }
                if(mid == 0){
                    int l = (nums.size()-(mpp[t].back()-mpp[t][0]))%nums.size();
                    int r = mpp[t][1]-mpp[t][0];
                    ans.push_back(min(l, r));
                }
                else if(mid == mpp[t].size()-1){
                    int l =(nums.size()-(mpp[t][mid]-mpp[t][0]))%nums.size();
                    int r = mpp[t][mid]-mpp[t][mid-1];
                    ans.push_back(min(l, r));
                }
                else {
                    int l = mpp[t][mid]-mpp[t][mid-1];
                    int r = mpp[t][mid+1]-mpp[t][mid];
                    ans.push_back(min(l, r));
                }
            }
        }
        return ans;
    }
};