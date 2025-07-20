class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int mx = 1;
        int n = nums.size();
        vector<vector<int>>dp(k , vector<int>(n,1) );

        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<i ; j++)
            {
                //LIS type of condition
                int modVal = ( nums[i] + nums[j] )%k; 

                //for same modVal adding +1 from prev length
                dp[modVal][i] = max(dp[modVal][i] , 1 + dp[modVal][j] );
                mx = max(mx , dp[modVal][i] );
            }
        }

        //O(n^2) time
        //O(k*n) space
        return mx;
    }
};