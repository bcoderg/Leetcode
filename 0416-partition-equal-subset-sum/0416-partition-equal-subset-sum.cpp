class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s=0 , n=nums.size();
        for(auto x:nums)s+=x;
        if(s&1)return false;
        s/=2;
        vector<vector<bool>>dp(n+1  , vector<bool>(s+1 , false));

        for(int  i=0;i<=n;i++)dp[i][0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=s;j++)
            {
                if(nums[i-1]<=j)
                {
                    dp[i][j]= dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<s;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return dp[n][s];

    }
};