class Solution {
public:
    vector<vector<int>>ans;
    void fun(int idx, vector<int>& v) {
        if (idx == v.size()) {
            ans.push_back(v); return;
        }

        unordered_map<int, bool>vis;
        for (int j = idx; j < v.size(); j++) {

            if (vis[v[j]])continue; //if same value came b4,swapped we can ignore to avoid duplicates


            swap(v[idx], v[j]); //swap values
            fun(idx + 1, v);
            swap(v[idx], v[j]); //restore
            vis[v[j]] = true;   //mark as vis
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& v) {
        sort(v.begin(), v.end());
        fun(0, v);
        return ans;
    }
};