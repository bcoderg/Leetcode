class RandomizedSet {
public:
    vector<int>v;
    unordered_map<int,int>mp;  
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())return false;
        v.push_back(val);
        mp[val]=v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())return false;
        //to delete in O(1) swap val,last idx ele , pop_back() last ele 
        int lastIdx = v.size() - 1;
        int curIdx = mp[val];
        mp[v.back()] = curIdx;  
        swap(v[curIdx] , v.back());
        mp.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */