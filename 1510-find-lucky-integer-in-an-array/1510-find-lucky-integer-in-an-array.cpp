class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto &x:arr)mp[x]++;
        int res=-1;
        for(auto &x:mp){
            if(x.first == x.second){
                res=max(res , x.first);
            }
        }
        return res;
    }
};