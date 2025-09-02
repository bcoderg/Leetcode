class Solution {
public:
    vector<vector<int>>dp;
    // int f(int idx , int buying , vector<int>& prices) {
    //     if (idx >= prices.size()) {
    //         return 0;
    //     }

    //     if (dp[idx][buying] != -1) {
    //         return dp[idx][buying];
    //     }

    //     int cooldown = f(idx + 1, buying, prices);
    //     if (buying) {
    //         int buy = f(idx + 1 , !buying , prices) - prices[idx];
    //         return dp[idx][buying] = max(cooldown , buy);
    //     }
    //     else {
    //         int sell = prices[idx] + f(idx + 2 , 1 , prices);
    //         return dp[idx][buying] = max(sell, cooldown);
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        // dp.assign(prices.size() , vector<int>(2,-1));
        //1 - buying , 0 - not buying
        //return f(0,1,prices);//idx , buying

        int n = prices.size();
        dp.assign(n+1 , vector<int>(2, 0));
        for (int idx = n-1 ; idx >= 0 ; idx--) {
            for (int buying = 1 ; buying >= 0 ; buying--) {
                int cooldown = dp[idx + 1][buying];
                if (buying==1) {
                    int buy = dp[idx + 1][!buying] - prices[idx];//if buy cur , not buy next
                    dp[idx][buying] = max(cooldown , buy);
                }
                else {
                    int sell = (idx+2 < n) ? dp[idx + 2][!buying] + prices[idx] : prices[idx];//if sell curr, can buy idx+2 th
                    dp[idx][buying] = max(sell, cooldown);
                }
            }
        }
        return dp[0][1];
    }
};