class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin() , nums.end() , 0);
        if(sum&1)return false;  
        sum>>=1;
        //2D dp
        // vector<vector<bool>>dp(n+1 , vector<bool>(sum+1 , 0));
        // for(int i=0;i<=n;i++)dp[i][0]=true; 

        // for(int i=1;i<=n;i++){
        //     for(int j=0;j<=sum ; j++){
        //         if(nums[i-1] <= j){
        //             dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
        //         }
        //         else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }
        // return dp[n][sum];

        //1D DP - can reuse 1 array it self works fine
        vector<bool>dp(sum+1 , false);
        dp[0] = true;  

        for(int i=1;i<=n;i++){
            //for(int j=0;j<=sum ; j++){
            for(int j=sum; j>=0 ; j--){ //as we are using j - nums[i] , prev values should be computed
                if(nums[i-1] <= j){
                    dp[j] = dp[j] || dp[j - nums[i-1]];
                }
            }
        }
        return dp[sum];
    }
};