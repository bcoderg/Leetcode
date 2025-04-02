class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,-1);
        stack<int>stk; 
        for(int i=2*n - 1 ; i >= 0 ; i--){
            while(!stk.empty() && nums[stk.top()] <= nums[i%n]){
                stk.pop();
            }
            if(!stk.empty())ans[i%n]=nums[stk.top()];
            stk.push(i%n);
        }
        return ans; 
    }
};