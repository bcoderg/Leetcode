class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int mx=0 , s = 0;
        int l = 0 , r = 0 , n = nums.size();
        unordered_map<int , int>mp;
        while(l<=r && r<n)
        {
            mp[nums[r]]++; 
            s += nums[r];
            while(mp[nums[r]] > 1){
                mp[nums[l]]--;
                s -= nums[l]; 
                l++;
            } 
            mx = max(mx , s);
            r++;
        }
        return mx;
    }
};