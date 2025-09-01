class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint>dp(amount+1 , 0);
        dp[0] = 1; //only 1 way to get 0 

        for(int coin: coins){
            for(int i=1;i<=amount;i++){
                if(i>=coin){//to fit in coin in change i>=coin is must
                    dp[i] += dp[i-coin]; 
                }
            }
        }
        return dp[amount];
    }
};