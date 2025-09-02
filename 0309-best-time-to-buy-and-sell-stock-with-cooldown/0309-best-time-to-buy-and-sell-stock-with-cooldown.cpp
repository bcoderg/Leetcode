class Solution {
public:
    vector<vector<int>>dp;
    int f(int idx , int buying ,vector<int>& prices){
        if(idx>=prices.size()){
            return 0;
        }

        if(dp[idx][buying] != -1){
            return dp[idx][buying];
        }

        int cooldown = f(idx+1,buying,prices);
        if(buying){
            int buy = f(idx+1 , !buying , prices) - prices[idx];
            return dp[idx][buying] = max(cooldown , buy);
        }
        else{
            int sell = prices[idx] + f(idx+2 , 1 , prices);
            return dp[idx][buying] = max(sell,cooldown);
        }
    }
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size() , vector<int>(2,-1));
        //1 - buying , 0 - not buying
        return f(0,1,prices);//idx , buying
    }
};