class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int mx = 0;
        int n = nums.size();
        int zeroC = 0 , l = 0 , r = 0; 
        while(r < n){
            if(nums[r]==0)zeroC++;

            while(l<=r && zeroC > k){
                if(nums[l++]==0)zeroC--;
            }
            mx = max(mx , r - l + 1);
            r++;
        }
        return mx;
    }
};