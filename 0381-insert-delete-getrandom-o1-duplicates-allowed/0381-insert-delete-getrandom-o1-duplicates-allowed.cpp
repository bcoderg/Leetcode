class RandomizedCollection {
public:
    vector<pair<int,int>> nums;  // {val, idx in map's value}
    unordered_map<int, vector<int>> valToIndices;  // val -> {indices of val occurrences}
    
    RandomizedCollection() {}

    bool insert(int val) {
        valToIndices[val].push_back(nums.size());
        nums.push_back({val, valToIndices[val].size() - 1});
        return valToIndices[val].size() == 1;  // size 1 - first occurrence
    }

    bool remove(int val) {
        if (valToIndices[val].empty()) return false;

        auto [lastValue, lastValueIdx] = nums.back();
        int indexToRemove = valToIndices[val].back();

        valToIndices[lastValue][lastValueIdx] = indexToRemove;
        nums[indexToRemove] = {lastValue, lastValueIdx};

        nums.pop_back();
        valToIndices[val].pop_back();

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};