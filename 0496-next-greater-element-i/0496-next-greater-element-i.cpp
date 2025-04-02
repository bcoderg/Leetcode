class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums2.size();
        unordered_map<int, int> mp;
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums2[stk.top()] < nums2[i]) {
                mp[nums2[stk.top()]] = nums2[i];
                stk.pop();
            }
            stk.push(i);
        }
        vector<int>ans;
        for (int &num : nums1) {
            if (mp.find(num) != mp.end()) {
                ans.push_back(mp[num]);
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};